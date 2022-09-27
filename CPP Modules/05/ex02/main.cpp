/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Jun  1 16:21:46 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "header.hpp"

int		main(void)
{
	/* Init Buraucrats */
	Bureaucrat	a, b("Jamie", 68), c("Luke", 16), d("Master Yoda", 1);

	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;
	std::cout << "D: " << d << std::endl;

	std::cout << std::endl;

	///////////////////// CONDITIONS /////////////////////
	/*   Testing each conditions where they must fails  */

	/* ATTEMPT ONE */
	try {
		PresidentialPardonForm	form;
		form.beSigned(a);
		form.execute(a);
	}
	catch (std::exception &error) {
		std::cout << a << " tried to execute a form but failed: " << error.what() << std::endl;
	}

	/* ATTEMPT TWO */
	try {
		PresidentialPardonForm	form;
		form.beSigned(b);
		form.execute(b);
	}
	catch (std::exception &error) {
		std::cout << b << " tried to execute a form but failed: " << error.what() << std::endl;
	}

	/* ATTEMPT THREE */
	try {
		PresidentialPardonForm	form;
		form.beSigned(c);
		form.execute(c);
	}
	catch (std::exception &error) {
		std::cout << c << " tried to execute a form but failed: " << error.what() << std::endl;
	}


	//////////////// EXECUTION ////////////////
	/*   Testing each Forms functionalities  */

	try {
		PresidentialPardonForm	form("Trump");
		form.beSigned(d);
		form.execute(d);
	}
	catch (std::exception &error) {
		std::cout << d << " tried to execute a form but failed: " << error.what() << std::endl;
	}

	try {
		RobotomyRequestForm		form("Amazon");
		form.beSigned(d);
		form.execute(d);
	}
	catch (std::exception &error) {
		std::cout << d << " tried to execute a form but failed: " << error.what() << std::endl;
	}

	try {
		ShrubberyCreationForm	form("super");
		form.beSigned(d);
		form.execute(d);
	}
	catch (std::exception &error) {
		std::cout << d << " tried to execute a form but failed: " << error.what() << std::endl;
	}
}