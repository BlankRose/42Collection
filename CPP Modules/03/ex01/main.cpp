/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 20:25:05 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "ScavTrap.hpp"
#include <iostream>

int		main(void)
{
	ClapTrap	newbie("Steve");
	ScavTrap	a, b("JOHN CENA"), c(b), d("Random"), e;

	e = c;
	c = d;

	std::cout << std::endl;

	newbie.attack("dummy");
	a.attack("Steve");
	newbie.takeDamage(10);
	b.beRepaired(46);
	e.takeDamage(9999);
	c.guardGate();

	std::cout << std::endl;
}