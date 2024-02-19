/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  stat.c                                                 */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 12, 2024 [07:34 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "ft_ls.h"

e_err ls_stat_folder(s_dir *dir, const s_args *args)
{
	const size_t  n = len(dir->path);
	char *        base = NULL;
	char *        tmp  = NULL;

	// PREVENT STATS WHEN UNNECESSARY
	if (!hasBit(args->flags, FLAG_LONG)
			&& (args->sort == SORT_NONE || args->sort == SORT_ALPHABETIC))
		return ERR_NONE;

	// PREPARE BASIC MEMORY
	dir->stats = malloc(dir->total * sizeof(s_stat));
	if (!dir->stats)
		return ERR_ALLOC;
	if (dir->path && n > 0)
	{
		if (dir->path[n - 1] == '/')
			base = mdup(dir->path, n + 1);
		else
			base = join(dir->path, "/");
		if (!base)
			return (free(dir->stats), ERR_ALLOC);
	}

	// LOAD CONTENT STATS
	for (ssize_t i = 0; i < dir->total; i++)
	{
		if (base)
		{
			tmp = join(base, get_path(dir, i));
			if (!tmp || lstat(tmp, &dir->stats[i]) < 0)
				for (size_t y = 0; y < sizeof(s_stat); y++)
					((unsigned char *) &dir->stats[i])[y] = 0;
			free(tmp);
		}
		else if (lstat(get_path(dir, i), &dir->stats[i]) < 0)
			for (size_t y = 0; y < sizeof(s_stat); y++)
				((unsigned char *) &dir->stats[i])[y] = 0;
	}
	free(base);
	return ERR_NONE;
}

e_err ls_clear_dots(s_dir *dir)
{
	ssize_t      new_len   = 0;
	s_dirent **  new_files = NULL;

	// GET NEW LENGTH WITHOUT DOT FILES
	for (ssize_t i = 0; i < dir->total; i++)
		if (dir->content.files[i]->d_name[0] != '.')
			new_len++;
	if (!new_len)
	{
		for (ssize_t i = 0; i < dir->total; i++)
			free(dir->content.files[i]);
		goto skip_copy;
	}

	// PREPARE NEW MEMORY
	new_files = malloc(new_len * sizeof(s_dirent *));
	if (!new_files)
		return ERR_ALLOC;

	// LOAD ALL NON DOT CONTENT IN
	for (ssize_t x = 0, y = 0; x < dir->total; x++)
	{
		if (dir->content.files[x]->d_name[0] != '.')
			new_files[y++] = dir->content.files[x];
		else
			free(dir->content.files[x]);
	}

	// CLEAR AND REPLACE
skip_copy:
	free(dir->content.files);
	dir->total = new_len;
	dir->content.files = new_files;
	return ERR_NONE;
}

void clear_dir(s_dir *dir)
{
	if (!dir)
		return;
	if (dir->stats)
		free(dir->stats);
	if (dir->content.files && dir->path)
		for (ssize_t i = 0; i < dir->total; i++)
			free(dir->content.files[i]);
	free(dir->content.files);
}
