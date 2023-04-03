/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - WrongCat.cpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 06:45:35 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "WrongCat.hpp"
#include <iostream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

WrongCat::WrongCat():
	WrongAnimal::WrongAnimal("WrongCat")
{
	std::cout << "WRONG_CAT: default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat&):
	WrongAnimal::WrongAnimal("WrongCat")
{
	std::cout << "WRONG_CAT: clone constructor called!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WRONG_CAT: destructor called!" << std::endl;
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

WrongCat		&WrongCat::operator=(const WrongCat &d)
{
	WrongAnimal::operator=(d);
	return *this;
}