/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - whatever.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 19:27:35 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __WHATEVER_HPP__
# define __WHATEVER_HPP__

#include <iostream>

template<typename T>
void		swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T		&min(const T &a, const T &b)
{
	if (a < b) return a;
	return b;
}

template<typename T>
const T		&max(const T &a, const T &b)
{
	if (b < a) return a;
	return b;
}

#endif