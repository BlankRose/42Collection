/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  directory.c                                            */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 04, 2024 [05:17 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "utils.h"
#include <dirent.h>

ssize_t dirlen(const char *path)
{
	DIR *       dir = opendir(path);
	s_dirent *  buf = NULL;
	ssize_t     len = 0;

	if (!dir)
		return -1;
	while ((buf = readdir(dir)))
		len++;
	closedir(dir);
	return len;
}

int hasAccess(const char *path)
{
	DIR *  dir = opendir(path);

	if (!dir)
		return 0;
	closedir(dir);
	return 1;
}
