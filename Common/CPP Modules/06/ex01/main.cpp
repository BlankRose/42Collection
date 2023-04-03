/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 17:51:42 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "header.hpp"

int		main(void)
{
	Data	*test = new Data;
	
	test->nb = 456;
	test->str = "I like turtles";

	std::cout << "TEST:" << std::endl
			  << "NB = " << test->nb << std::endl
			  << "STR = " << test->str << std::endl;

	std::cout << "\nSerializing TEST and save into I and" << std::endl
			  << "using I to Deserialize into DST...\n" << std::endl;
	uintptr_t	i = serialize (test);
	Data		*dst = deserialize(i);

	std::cout << "DST:" << std::endl
			  << "NB = " << dst->nb << std::endl
			  << "STR = " << dst->str << std::endl;
}