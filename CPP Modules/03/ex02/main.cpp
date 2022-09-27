/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 20:37:10 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "FragTrap.hpp"
#include <iostream>

int		main(void)
{
	ClapTrap	newbie("Steve");
	FragTrap	a, b("JOHN CENA"), c(b), d("Random"), e;

	e = c;
	c = d;

	std::cout << std::endl;

	newbie.attack("dummy");
	a.attack("Steve");
	newbie.takeDamage(10);
	b.beRepaired(46);
	e.takeDamage(9999);
	c.highFivesGuys();

	std::cout << std::endl;
}