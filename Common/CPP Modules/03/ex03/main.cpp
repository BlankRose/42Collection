/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 22:29:18 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "DiamondTrap.hpp"
#include <iostream>

int		main(void)
{
	DiamondTrap		test;

	std::cout << std::endl;

	test.attack("Steve");
	test.beRepaired(50);
	test.takeDamage(20);
	test.guardGate();
	test.highFivesGuys();
	test.whoAmI();

	std::cout << std::endl;
}