/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   LibASM - tools.h                                */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Apr 13 14:44:18 CEST 2023     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __TOOLS__
# define __TOOLS__

# include "libasm.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void		test_in_out(char *s);
void		test_status(char *s1, char *s2);
void		test_clone(char *s1, char *s2);

t_list *	test_insert(void);
void		test_destroy(t_list **lst);
void		test_atoi(void);

#endif /* __TOOLS__ */