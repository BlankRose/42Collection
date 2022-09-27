/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - verify.cpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 18:29:08 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "header.hpp"

Base*	generate(void)
{
	// Selects a random Index
	int i = rand() % 3;

	// Returns the corresponding base
	if (i == 0) return new A();
	if (i == 1) return new B();
	else return new C();
}

void	identify(Base *p)
{
	A*	a;
	if ((a = dynamic_cast<A*> (p)))
		std::cout << "A" << std::endl;
	
	B*	b;
	if ((b = dynamic_cast<B*> (p)))
		std::cout << "B" << std::endl;

	C*	c;
	if ((c = dynamic_cast<C*> (p)))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&> (p);
		(void) a;
		std::cout << "A" << std::endl;
	} catch (...) {}

	try {
		B &b = dynamic_cast<B&> (p);
		(void) b;
		std::cout << "B" << std::endl;
	} catch (...) {}

	try {
		C &c = dynamic_cast<C&> (p);
		(void) c;
		std::cout << "C" << std::endl;
	} catch (...) {}
}