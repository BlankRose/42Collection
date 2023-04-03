/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 20:57:39 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Array.hpp"
#include <random>

int		main(void)
{
	srand(time(NULL));

	/* Integer */
	Array<int>			y(6);

	for (size_t i = 0; i < y.size(); i++)
		y[i] = rand() % 1000;

	for (size_t i = 0; i < y.size(); i++)
		std::cout << y[i] << " ; ";
	std::cout << std::endl;

	/* Strings */
	Array<std::string>	s(3);

	s[0] = "I like turtles";
	s[1] = " because yes ";
	s[2] = "they very kewl";

	for (size_t i = 0; i < s.size(); i++)
		std::cout << s[i];
	std::cout << std::endl;
}