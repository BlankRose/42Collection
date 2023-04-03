/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Brain.cpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 08:14:36 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Brain.hpp"
#include <iostream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Brain::Brain()
{
	std::cout << "BRAIN: default constructor called!" << std::endl;
	this->ideas = new std::string[100];
}

Brain::Brain(const Brain &b)
{
	std::cout << "BRAIN: clone constructor called!" << std::endl;
	this->ideas	= new std::string[100];

	for (int i = 0; i < 100; i++){
		this->ideas[i] = b.ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "BRAIN: destructor called!" << std::endl;
	delete[] this->ideas;
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Brain	&Brain::operator=(const Brain &b)
{
	if (!this->ideas)
		this->ideas = new std::string[100];

	for (int i = 0; i < 100; i++){
		this->ideas[i] = b.ideas[i];
	}

	return *this;
}