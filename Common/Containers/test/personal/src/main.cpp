/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - main.cpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sat Nov 12 15:42:49 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "test.hpp"

int		main(int, char **)
{
#ifdef CHECK_VECTOR
	NEW_TITLE(31, "VECTORS TESTING")
	test_vector();
	std::cout << std::endl;
#endif

#ifdef CHECK_STACK
	NEW_TITLE(33, "STACK TESTING")
	test_stack();
	std::cout << std::endl;
#endif

#ifdef CHECK_MAP
	NEW_TITLE(32, "MAP TESTING")
	test_map();
	std::cout << std::endl;
#endif
}