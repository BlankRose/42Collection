/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 20:26:35 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "ClapTrap.hpp"
#include <iostream>

int		main(void)
{
	ClapTrap	a, b("JOHN CENA"), c(b), d("Random"), e;

	e = c;

	std::cout << std::endl;

	a.attack("Steve");
	a.attack(d);
	b.beRepaired(15);
	d.takeDamage(3);
	e.takeDamage(78);

	std::cout << std::endl;
}