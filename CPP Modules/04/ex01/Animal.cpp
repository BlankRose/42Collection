/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Animal.cpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 06:29:51 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Animal.hpp"
#include <iostream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Animal::Animal()
{
	std::cout << "ANIMAL: default constructor called!" << std::endl;
	this->type = "";
}

Animal::Animal(const std::string &type)
{
	std::cout << "ANIMAL: string constructor called!" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal &a)
{
	std::cout << "ANIMAL: clone constructor called!" << std::endl;
	this->type = a.type;
}

Animal::~Animal()
{
	std::cout << "ANIMAL: destructor called!" << std::endl;
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Animal		&Animal::operator=(const Animal &a)
{
	this->type = a.type;
	return *this;
}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

void		Animal::makeSound(void)
{
	if (this->type == "Cat")
		std::cout << "Meow!" << std::endl;
	
	if (this->type == "Dog")
		std::cout << "Woof!" << std::endl;
}

std::string		Animal::getType(void)
{
	if (!this->type.empty())
		return this->type;
	return "None";
}