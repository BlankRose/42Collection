/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Jun  1 17:56:57 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Intern.hpp"

int		main(void)
{
	Intern	a;
	Form	*f;

	f = a.makeForm("NonExistant", "jungle");
	f = a.makeForm("RobotomyRequestForm", "China");

	std::cout << *f << std::endl;
}