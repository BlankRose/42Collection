/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  main.c                                                 */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 14, 2024 [05:23 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	s_args *  args = ls_init(argc, argv);
	int       ret;

	if (args == (void *) 0x01)
		return 0;
	if (!args)
		return 2;

	ret = ls_start_unfold(args);
	ls_end(args);
	return ret;
}
