/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Dog.cpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 07:43:09 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Dog.hpp"
#include <iostream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Dog::Dog():
	Animal::Animal("Dog")
{
	std::cout << "DOG: default constructor called!" << std::endl;
	this->ideas = new Brain();
}

Dog::Dog(const Dog &d):
	Animal::Animal("Dog")
{
	std::cout << "DOG: clone constructor called!" << std::endl;
	this->ideas = new Brain(*(d.ideas));
}

Dog::~Dog()
{
	std::cout << "DOG: destructor called!" << std::endl;
	delete this->ideas;
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Dog		&Dog::operator=(const Dog &d)
{
	Animal::operator=(d);
	*(this->ideas) = *(d.ideas);
	return *this;
}