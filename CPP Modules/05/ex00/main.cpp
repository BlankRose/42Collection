/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 13:52:04 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Bureaucrat.hpp"
#include <iostream>

int		main(void)
{
	/* ATTEMPT ONE: Default Constructor */
	try {
		Bureaucrat	b;
		std::cout << b << std::endl;
	}
	catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	/* ATTEMPT TWO: Setup Constructor (Inbound) */
	try {
		Bureaucrat	b("Jamie", 48);
		std::cout << b << std::endl;
		b.gradeDown();
		std::cout << "He's also getting downgraded! Now grade " << b.getGrade() << std::endl;
	}
	catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	/* ATTEMPT THREE: Setup Constructor (Low) */
	try {
		Bureaucrat	b("Cake Boi", -89);
		std::cout << b << std::endl;
	}
	catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	/* ATTEMPT FOUR: Setup Constructor (Far) */
	try {
		Bureaucrat	b("Cake Boi", 456);
		std::cout << b << std::endl;
	}
	catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	/* ATTEMPT FIVE: Clone Constructor */
	try {
		Bureaucrat	b("Luke", 16), c(b);
		std::cout << c << std::endl;
		c.gradeUp();
		std::cout << "He's also getting promoted! Now grade " << c.getGrade() << std::endl;
	}
	catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
}