/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - easyfind.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 21:36:56 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

#include <iostream>
#include <algorithm>
#include <exception>
#include <random>

class NotFound: public std::exception
{
	public:
		virtual const char *what() const throw()
			{return "Couldn't find value!";}
};

template <class T>
typename T::iterator	easyfind(T &container, int search)
{
	typename T::iterator res = find(container.begin(), container.end(), search);
	
	if (res == container.end())
		throw NotFound();
	return res;
}

#endif