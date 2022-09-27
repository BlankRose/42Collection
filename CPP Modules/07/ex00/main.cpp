/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 19:34:07 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "whatever.hpp"

int		main(void)
{
	int		a = 5, b = 8;
	double	x = 0.58, y = 486.0;


	std::cout << "SWAP: (Before / After)" << std::endl;
	/* INT */
	std::cout << "a = " << a << " | b = " << b << std::endl;
	swap(a, b);
	std::cout << "a = " << a << " | b = " << b << std::endl;
	/* DOUBLE */
	std::cout << "x = " << x << " | y = " << y << std::endl;
	swap(x, y);
	std::cout << "x = " << x << " | y = " << y << std::endl;


	std::cout << "MIN:" << std::endl;
	/* INT */
	std::cout << "min(a, b) : " << min(a, b) << std::endl;
	/* DOUBLE */
	std::cout << "min(x, y) : " << min(x, y) << std::endl;


	std::cout << "MAX:" << std::endl;
	/* INT */
	std::cout << "max(a, b) : " << max(a, b) << std::endl;
	/* DOUBLE */
	std::cout << "max(x, y) : " << max(x, y) << std::endl;
}