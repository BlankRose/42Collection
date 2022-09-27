/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Cat.cpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 08:39:54 CEST 2022     */
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
	this->ideas = new Brain();
}

Cat::Cat(const Cat &c):
	Animal::Animal("Cat")
{
	std::cout << "CAT: clone constructor called!" << std::endl;
	this->ideas = new Brain(*(c.ideas));
}

Cat::~Cat()
{
	std::cout << "CAT: destructor called!" << std::endl;
	delete this->ideas;
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
	*(this->ideas) = *(d.ideas);
	return *this;
}