/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  unfold.c                                               */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 15, 2024 [11:37 am]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "ft_ls.h"

/**
 * === UNFOLD ===
 * 
 * Handles the unfolding of system files folders,
 * preparing for listing and printing
 * */

static e_err ls_next_files(s_args *args, const int do_all);
static e_err ls_next_folder(const char *path, s_args *args);
static e_err ls_next_recursive(const s_dir *dir, s_args *args);
static void copy_dirent(s_dirent *dir, const s_dirent *buffer);

int ls_start_unfold(s_args *args)
{
	e_err  last  = ERR_NONE;
	int    final = 0;

	// UPON DIRECTORY FLAG, INTERPRET ALL AS FILES
	if (hasBit(args->flags, FLAG_DIRECTORY))
	{
		if (ls_next_files(args, 1) != ERR_NONE)
			return 2;
		return 0;
	}

	// TARGET PROVIDED FILES
	last = ls_next_files(args, 0);
	if (last != ERR_NONE)
		final = 2;

	// TARGET PROVIDED DIRECTORIES
	for (size_t i = 0; i < args->count; i++)
	{
		if (!args->targets[i].path)
			final = 2;
		if (!args->targets[i].path || !args->targets[i].is_dir)
			continue;
		last = ls_next_folder(args->targets[i].path, args);

		// CHECK ERRORS
		switch (last)
		{
			case ERR_NONE:
				break;
			case ERR_ALLOC:
				swrite(2, "ft_ls: memory allocation failure\n");
				return 2;
			case ERR_SUBDIR:
				final = 1;
				break;
			default:
				print(2, "ft_ls: cannot access '%s': ", args->targets[i]);
				if (!errno)
					swrite(1, "Unknown error\n");
				else
					perror(NULL);
				final = 2;
		}
	}

	return final;
}

static
e_err ls_next_files(s_args *args, const int do_all)
{
	s_dir        dir = { NULL, NULL, 0, { NULL } };
	e_err        err = ERR_NONE;

	// COUNT TARGETS
	for (size_t i = 0; i < args->count; i++)
	{
		if (!args->targets[i].path)
			err = ERR_OPENDIR;
		else if (do_all || !args->targets[i].is_dir)
			dir.total++;
	}

	// PREPARE MEMORY
	dir.content.paths = malloc(dir.total * sizeof(char *));
	if (!dir.content.paths)
		return (mem_error(NULL, 0), ERR_ALLOC);

	// ASSIGN PATHS TO DISPLAY
	for (size_t x = 0, y = 0; x < args->count; x++)
		if (args->targets[x].path && (do_all || !args->targets[x].is_dir))
			dir.content.paths[y++] = args->targets[x].path;

	// SORT AND PRINT
	if (ls_stat_folder(&dir, args) != ERR_NONE)
		return (free(dir.content.paths), ERR_ALLOC);
	if (args->sort != SORT_NONE)
	{
		ls_sort(&dir, args->sort);
		if (hasBit(args->flags, FLAG_REVERSE))
			ls_reverse(&dir);
	}
	print_folder(args, &dir);

	free(dir.stats);
	free(dir.content.paths);
	return err;
}

static
e_err ls_next_folder(const char *path, s_args *args)
{
	s_dir        dir    = { path, NULL, dirlen(path), { NULL } };
	DIR *        stream = NULL;
	s_dirent *   buffer = NULL;
	e_err        ret    = ERR_NONE;

	// PREPARE MEMORY
	if (dir.total < 0)
		return ERR_OPENDIR;
	dir.content.files = malloc(dir.total * sizeof(s_dirent *));
	if (!dir.content.files)
		return ERR_ALLOC;

	// LOAD ALL CONTENT IN
	stream = opendir(path);
	if (!stream)
		return (free(dir.content.files), ERR_OPENDIR);
	for (ssize_t i = 0; i < dir.total; i++)
	{
		// READ NEXT TARGET
		buffer = readdir(stream);
		if (buffer)
		{
			dir.content.files[i] = malloc(sizeof(s_dirent));
			if (dir.content.files[i])
				copy_dirent(dir.content.files[i], buffer);
			else
				ret = ERR_ALLOC;
		}
		else
		{
			dir.content.files[i] = NULL;
			ret = ERR_READDIR;
		}

		// FAILURE HANDLING
		if (!buffer || !dir.content.files[i])
		{
			for (ssize_t y = 0; y < i; y++)
				free(dir.content.files[y]);
			closedir(stream);
			free(dir.content.files);
			return ret;
		}
	}
	closedir(stream);

	// SORT AND PRINT
	if (!hasBit(args->flags, FLAG_ALL)
		&& ls_clear_dots(&dir) != ERR_NONE)
		return (clear_dir(&dir), ERR_ALLOC);
	if (ls_stat_folder(&dir, args) != ERR_NONE)
		return (clear_dir(&dir), ERR_ALLOC);
	if (args->sort != SORT_NONE)
	{
		ls_sort(&dir, args->sort);
		if (hasBit(args->flags, FLAG_REVERSE))
			ls_reverse(&dir);
	}
	print_folder(args, &dir);

	// RECURSE IF NECCESSARY
	if (hasBit(args->flags, FLAG_RECURSIVE))
		ret = ls_next_recursive(&dir, args);

	// CLOSE STREAMS
	clear_dir(&dir);
	return ret;
}

static
e_err ls_next_recursive(const s_dir *dir, s_args *args)
{
	char **    paths = malloc(dir->total * sizeof(char *));
	char *     tmp   = NULL;
	e_err      last  = ERR_NONE;
	e_err      out   = ERR_NONE;

	if (!paths)
		return ERR_ALLOC;
	if (dir->path[len(dir->path) - 1] != '/')
	{
		tmp = join(dir->path, "/");
		if (!tmp)
			return (free(paths), ERR_ALLOC);
	}
	for (ssize_t i = 0; i < dir->total; i++)
	{
		// SKIPS NON-DIRECTORIES
		if (dir->content.files[i]->d_type != DT_DIR
			|| cmp(dir->content.files[i]->d_name, ".", 2)
			|| cmp(dir->content.files[i]->d_name, "..", 3))
			continue;

		// BUILD PATH
		if (tmp)
			paths[i] = join(tmp, dir->content.files[i]->d_name);
		else
			paths[i] = join(dir->path, dir->content.files[i]->d_name);

		// FREE UPON FAILURE
		if (!paths[i])
		{
			for (ssize_t e = 0; e < i; e++)
			{
				if (dir->content.files[e]->d_type != DT_DIR
					|| cmp(dir->content.files[e]->d_name, ".", 2)
					|| cmp(dir->content.files[e]->d_name, "..", 3))
					continue;
				free(paths[e]);
			}
			free(paths);
			free(tmp);
			return ERR_ALLOC;
		}

		// CHECKS IF ACCESS
		if (!hasAccess(paths[i]))
		{
			print(2, "ft_ls: cannot access '%s': ", paths[i]);
			perror(NULL);
			out = ERR_SUBDIR;
		}
	}
	free(tmp);

	// APPLY FUNCTION ON SUB DIRECTORIES
	for (ssize_t i = 0; i < dir->total; i++)
	{
		if (dir->content.files[i]->d_type != DT_DIR
			|| cmp(dir->content.files[i]->d_name, ".", 2)
			|| cmp(dir->content.files[i]->d_name, "..", 3))
			continue;
		last = ls_next_folder(paths[i], args);
		if (last == ERR_ALLOC)
			out = last;
		else if (last != ERR_ALLOC)
			out = ERR_SUBDIR;
	}

	// FREE USED MEMORY
	for (ssize_t i = 0; i < dir->total; i++)
	{
		if (dir->content.files[i]->d_type != DT_DIR
			|| cmp(dir->content.files[i]->d_name, ".", 2)
			|| cmp(dir->content.files[i]->d_name, "..", 3))
			continue;
		free(paths[i]);
	}
	free(paths);
	return out;
}

static
void copy_dirent(s_dirent *dir, const s_dirent *buffer)
{
	const size_t  n = len(buffer->d_name);

	dir->d_ino = buffer->d_ino;
	dir->d_off = buffer->d_off;
	dir->d_reclen = buffer->d_reclen;
	dir->d_type = buffer->d_type;
	copy(buffer->d_name, dir->d_name, n);
	dir->d_name[n] = '\0';
}
