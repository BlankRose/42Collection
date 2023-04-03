/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 18:31:51 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "header.hpp"

int		main(void)
{
	Base	*p;
	srand(time(NULL));

	/* Set One */
	p = generate();
	std::cout << "Set One:" << std::endl;
	identify(p);
	identify(*p);
	delete p;

	/* Set Two */
	p = generate();
	std::cout << "Set Two:" << std::endl;
	identify(p);
	identify(*p);
	delete p;

	/* Set Three */
	p = generate();
	std::cout << "Set Three:" << std::endl;
	identify(p);
	identify(*p);
	delete p;

	/* Set Four */
	p = generate();
	std::cout << "Set Four:" << std::endl;
	identify(p);
	identify(*p);
	delete p;

	/* Set Five */
	p = generate();
	std::cout << "Set Five:" << std::endl;
	identify(p);
	identify(*p);
	delete p;
}