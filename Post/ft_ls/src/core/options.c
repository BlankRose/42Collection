/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  options.c                                              */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 14, 2024 [03:18 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "ft_ls.h"

/**
 * === OPTIONS ===
 * 
 * Contains all the neccessary functions
 * to parse the options and arguments provided
 * to the programm
 * */

void parse_options(int argc, char **argv, s_args *args)
{
	for (int i = 1; i < argc; i++)
	{
		// SKIP NON-OPTION ARGUMENTS
		if (!argv[i] || argv[i][0] != '-' || !argv[i][1])
			continue;

		// HANDLE NAMED ARGUMENTS
		if (argv[i][1] == '-')
		{
			if (!argv[i][2]) // -- (STOP PARSE)
				break;
			else if (cmp(argv[i], "--all", -1))
				setBits(args->flags, FLAG_ALL);
			else if (cmp(argv[i], "--recursive", -1))
				setBits(args->flags, FLAG_RECURSIVE);
			else if (cmp(argv[i], "--reverse", -1))
				setBits(args->flags, FLAG_REVERSE);
			else if (cmp(argv[i], "--directory", -1))
				setBits(args->flags, FLAG_DIRECTORY);
			else if (cmp(argv[i], "--color", -1))
				setBits(args->flags, FLAG_COLOR);
			else if (cmp(argv[i], "--color=", 7))
			{
				const char *  sub = &argv[i][8];

				if (!*sub)
				{
					color_error(&args->flags, "", "ambiguous argument");
					return;
				}				
				else if (cmp(sub, "always", -1) || cmp(sub, "yes", -1) || cmp(sub, "force", -1))
					setBits(args->flags, FLAG_COLOR);
				else if (cmp(sub, "never", -1) || cmp(sub, "no", -1) || cmp(sub, "none", -1))
					delBits(args->flags, FLAG_COLOR);
				else if (cmp(sub, "auto", -1) || cmp(sub, "tty", -1) || cmp(sub, "if-tty", -1))
				{
					if (hasBit(args->flags, FLAG_REDIRECTED))
						delBits(args->flags, FLAG_COLOR);
					else
						setBits(args->flags, FLAG_COLOR);
				}
				else
				{
					color_error(&args->flags, sub, "invalid argument");
					return;
				}
			}
			else if (cmp(argv[i], "--block-size=", 12))
			{
				const char *  sub = &argv[i][13];
				if (len(sub) >= 20)
				{
					print(1, "ft_ls: --block-size argument '%s' too large\n", sub);
					setBits(args->flags, FLAG_ERROR);
					return;
				}

				size_t  val = stoi(sub);
				if (!val)
				{
					print(1, "ft_ls: invalid --block-size argument '%s'\n", sub);
					setBits(args->flags, FLAG_ERROR);
					return;
				}
				setBits(args->flags, FLAG_BLKSIZE);
				args->blksize = val;
			}
			else if (cmp(argv[i], "--help", -1))
			{
				print_help();
				args->flags = -1;
				return;
			}
			else
			{
				opt_error(&args->flags, "unrecognized option", argv[i]);
				return;
			}
		}

		// HANDLE CHAINED ARGUMENTS
		else
			for (size_t x = 1; argv[i][x]; x++)
				switch (argv[i][x])
				{
					// OUTPUT FLAGS
					case 'f':
						args->sort = SORT_NONE;
						delBits(args->flags, FLAG_COLOR);
					case 'a':
						setBits(args->flags, FLAG_ALL);
						break;
					case 'R':
						setBits(args->flags, FLAG_RECURSIVE);
						break;
					case 'r':
						setBits(args->flags, FLAG_REVERSE);
						break;
					case 'o':
						setBits(args->flags, FLAG_HIDEGROUP | FLAG_LONG);
						break;
					case 'g':
						setBits(args->flags, FLAG_HIDEOWNER | FLAG_LONG);
						break;
					case 'l':
						setBits(args->flags, FLAG_LONG);
						break;
					case 'd':
						setBits(args->flags, FLAG_DIRECTORY);
						break;
					case '1':
						setBits(args->flags, FLAG_SINGLE);
						delBits(args->flags, FLAG_MULTIPLE);
						break;
					case 'C':
						setBits(args->flags, FLAG_MULTIPLE);
						delBits(args->flags, FLAG_SINGLE);
						break;

					// SORT FLAGS
					case 'U':
						args->sort = SORT_NONE;
						break;
					case 'u':
						setBits(args->flags, FLAG_ATIME);
						delBits(args->flags, FLAG_CTIME);
						break;
					case 't':
						args->sort = SORT_MOD_TIME;
						break;
					case 'c':
						setBits(args->flags, FLAG_CTIME);
						setBits(args->flags, FLAG_ATIME);
						break;
					case 'S':
						args->sort = SORT_SIZE;
						break;

					// INVALID FLAGS
					default:
						argv[i][x + 1] = '\0';
						opt_error(&args->flags, "invalid option --", &argv[i][x]);
						return;
				}
	}

	// HANDLE POST FLAGS HANDLE
	if (!hasBit(args->flags, FLAG_LONG)
		|| (hasBit(args->flags, FLAG_LONG) && args->sort == SORT_MOD_TIME))
	{
		if (hasBit(args->flags, FLAG_CTIME))
			args->sort = SORT_NEW_TIME;
		if (hasBit(args->flags, FLAG_ATIME))
			args->sort = SORT_ACCESS_TIME;
	}

	// HANDLE INCOMPATIBLE FLAGS
	if (args->sort == SORT_NONE)
		delBits(args->flags, FLAG_REVERSE);
	return;
}

char **parse_arguments(int argc, char **argv, size_t *store)
{
	// COUNT NON-OPTIONS ARGUMENTS
	size_t  total = 0;
	int     no_opt = 0;
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] && (argv[i][0] != '-'
				|| (argv[i][0] == '-' && (!argv[i][1] || no_opt))))
			total++;
		if (!no_opt && cmp(argv[i], "--", 3))
			no_opt = i;
	}

	// ALLOCATE NECCESARY MEMORY
	char **res = malloc((total > 0 ? total : 1) * sizeof(char *));
	if (!res)
		return mem_error(res, 0);

	// IF NO ARGUMENTS, ASSIGN TO CWD
	if (!total)
	{
		res[0] = sdup(".", 1);
		if (!res[0])
			return mem_error(res, 0);
		*store = 1;
	}

	// IF ARGUMENTS, STORE THEM
	else
	{
		size_t x = 0;
		for (int i = 1; i < argc; i++)
			if (argv[i] && (argv[i][0] != '-'
					|| (argv[i][0] == '-' && (!argv[i][1] || (no_opt && i > no_opt)))))
			{
				res[x] = sdup(argv[i], -1);
				if (!res[x])
					return mem_error(res, x);
				x++;
			}
		*store = total;
	}

	return res;
}
