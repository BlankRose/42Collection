/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - iter.hpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 19:48:49 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __ITER_HPP__
# define __ITER_HPP__

#include <iostream>

template<class T, class U, class C>
void	iter(T *tab, const U size, C f)
{
	for (U i = 0; i < size; i++)
		f(tab[i]);
}

#endif