/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 09:06:11 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int		main(void)
{
	Cat		*c = new Cat();
	Dog		*d = new Dog();

	std::cout << c->getType() << ": ";
	c->makeSound();

	std::cout << d->getType() << ": ";
	d->makeSound();

	delete c;
	delete d;

	return 0;
}