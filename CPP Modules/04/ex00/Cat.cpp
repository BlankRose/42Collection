/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Cat.cpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 06:20:52 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Cat.hpp"
#include <iostream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Cat::Cat():
	Animal::Animal("Cat")
{
	std::cout << "CAT: default constructor called!" << std::endl;
}

Cat::Cat(const Cat&):
	Animal::Animal("Cat")
{
	std::cout << "CAT: clone constructor called!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "CAT: destructor called!" << std::endl;
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Cat		&Cat::operator=(const Cat &d)
{
	Animal::operator=(d);
	return *this;
}