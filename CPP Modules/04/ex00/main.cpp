/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 06:55:55 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int		main(void)
{
	Animal	*meta = new Animal();
	std::cout << "Type is " << meta->getType() << std::endl;
	meta->makeSound();
	delete meta;

	std::cout << std::endl;

	Animal	*dog = new Dog();
	std::cout << "Type is " << dog->getType() << std::endl;
	dog->makeSound();
	delete dog;

	std::cout << std::endl;

	Animal	*cat = new Cat();
	std::cout << "Type is " << cat->getType() << std::endl;
	cat->makeSound();
	delete cat;

	std::cout << std::endl;

	WrongAnimal	*wmeta = new WrongAnimal();
	std::cout << "Type is " << wmeta->getType() << std::endl;
	wmeta->makeSound();
	delete wmeta;

	std::cout << std::endl;

	WrongAnimal	*wcat = new WrongCat();
	std::cout << "Type is " << wcat->getType() << std::endl;
	wcat->makeSound();
	delete wcat;

	return 0;
}