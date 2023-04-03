/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Jun  1 18:08:50 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int		main(void)
{
	/* Init Buraucrats */
	Bureaucrat	a, b("Jamie", 68), c("Luke", 16), d(a);

	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;
	std::cout << "D: " << d << std::endl;

	std::cout << std::endl;

	/* ATTEMPT ONE: Default constructor */
	try {
		Form	f;
		std::cout << f << std::endl;
	}
	catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	/* ATTEMPT ONE: Setup constructor */
	try {
		Form	f("Presidence", 32, 76);
		std::cout << f << std::endl;
	}
	catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	/* ATTEMPT ONE: Setup constructor (Out) */
	try {
		Form	f("Presidence", 32, 165);
		std::cout << f << std::endl;
	}
	catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	/* ATTEMPT ONE: Setup constructor (Out 2) */
	try {
		Form	f("Presidence", 0, 76);
		std::cout << f << std::endl;
	}
	catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	/* ATTEMPT ONE: Clone constructor */
	try {
		Form	f("Ruby", 84, 115), g(f);
		std::cout << g << std::endl;
	}
	catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	/* Init Forms */
	std::cout << std::endl;
	Form	fa, fb("Emergency", 68, 31), fc("Diamond", 130, 10), fd(fb);

	std::cout << "A: " << fa << std::endl;
	std::cout << "B: " << fb << std::endl;
	std::cout << "C: " << fc << std::endl;
	std::cout << "D: " << fd << std::endl;

	std::cout << std::endl;

	/* Checks wether Forms can be signed or not */
	try {a.signForm(fb);}
	catch (std::exception &error) {}

	try {b.signForm(fa);}
	catch (std::exception &error) {}

	try {c.signForm(fc);}
	catch (std::exception &error) {}

	try {d.signForm(fd);}
	catch (std::exception &error) {}

	try {c.signForm(fa);}
	catch (std::exception &error) {}

	try {b.signForm(fc);}
	catch (std::exception &error) {}
}