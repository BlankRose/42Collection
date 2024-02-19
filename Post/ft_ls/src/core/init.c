/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  init.c                                                 */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 14, 2024 [05:22 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "ft_ls.h"

/**
 * === INIT ===
 * 
 * Handles the initialization and also, later, the
 * destruction of all ressources used by the software
 * */

static void get_atty_info(s_args *args);
static s_target *verify_paths(s_args *args, char **paths);

s_args *ls_init(int argc, char **argv)
{
	// PREPARE BASE
	s_args *b = malloc(sizeof(s_args));
	if (!b)
		return NULL;
	*b = (s_args) { 0, SORT_ALPHABETIC, NULL, 0, 0, 1024 };
	get_atty_info(b);

	// PARSE OPTIONS
	parse_options(argc, argv, b);
	if (b->flags == (t_flags) -1)
		return (free(b), (void *) 0x01);
	if (hasBit(b->flags, FLAG_ERROR))
		return (free(b), NULL);

	// PARSE ARGUMENTS
	char **paths = parse_arguments(argc, argv, &b->count);
	if (!paths)
		return (free(b), NULL);
	b->targets = verify_paths(b, paths);
	if (!b->targets)
		return (free(b), NULL);

	return b;
}

void ls_end(s_args *args)
{
	// BASE PROTECTION
	if (!args)
		return;

	// RELEASE RESSOURCES
	if (args->targets)
	{
		for (size_t i = 0; i < args->count; i++)
			free(args->targets[i].path);
		free(args->targets);
	}
	free(args);
}

static
s_target *verify_paths(s_args *args, char **paths)
{
	s_target *   targets = NULL;
	struct stat  statbuf;

	// PREPARE MEMORY
	if (!paths)
		return NULL;
	targets = malloc(args->count * sizeof(s_target));
	if (!targets)
		return mem_error(paths, args->count);

	// ASSIGN MEMORY
	for (size_t i = 0; i < args->count; i++)
	{
		if (!paths[i])
			targets[i] = (s_target){ NULL, 0 };
		else if (lstat(paths[i], &statbuf) < 0)
		{
			print(1, "ft_ls: cannot access '%s': ", paths[i]);
			perror(NULL);
			free(paths[i]);
			targets[i] = (s_target){ NULL, 0 };
		}
		else
		{
			if (S_ISLNK(statbuf.st_mode))
			{
				if (stat(paths[i], &statbuf) < 0)
				{
					print(1, "ft_ls: cannot access '%s': ", paths[i]);
					perror(NULL);
					free(paths[i]);
					targets[i] = (s_target){ NULL, 0 };
				}
				else
					targets[i] = (s_target){ paths[i], S_ISDIR(statbuf.st_mode) };
			}
			else
				targets[i] = (s_target){ paths[i], S_ISDIR(statbuf.st_mode) };
		}
	}
	free(paths);
	return targets;
}

static
void get_atty_info(s_args *args)
{
	// DETECT REDIRECTED OUTPUT
	if (!isatty(STDOUT_FILENO))
	{
		setBits(args->flags, FLAG_REDIRECTED | FLAG_SINGLE);
		args->width = FAIL_SAFE_WIDTH;
		return;
	}
	setBits(args->flags, FLAG_MULTIPLE);

	// RETRIEVE TERMINAL WIDTH
	struct winsize  tty;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &tty) < 0
		|| !tty.ws_col)
		args->width = FAIL_SAFE_WIDTH;
	else
		args->width = tty.ws_col;
}
