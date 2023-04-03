/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - WrongAnimal.cpp                   */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 06:41:01 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "WrongAnimal.hpp"
#include <iostream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

WrongAnimal::WrongAnimal()
{
	std::cout << "WRONG_ANIMAL: default constructor called!" << std::endl;
	this->type = "";
}

WrongAnimal::WrongAnimal(const std::string &type)
{
	std::cout << "WRONG_ANIMAL: string constructor called!" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	std::cout << "WRONG_ANIMAL: clone constructor called!" << std::endl;
	this->type = a.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WRONG_ANIMAL: destructor called!" << std::endl;
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

WrongAnimal		&WrongAnimal::operator=(const WrongAnimal &a)
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

void		WrongAnimal::makeSound(void)
{
	if (this->type == "WrongCat")
		std::cout << "Mrrreeozw!" << std::endl;
}

std::string		WrongAnimal::getType(void)
{
	if (!this->type.empty())
		return this->type;
	return "None";
}