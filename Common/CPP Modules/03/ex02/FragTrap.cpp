/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - FragTrap.cpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 20:42:06 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "FragTrap.hpp"
#include <iostream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called!" << std::endl;

	this->hp = 100;
	this->mp = 100;
	this->atk = 30;
}

FragTrap::FragTrap(const std::string &name):
	ClapTrap::ClapTrap(name)
{
	std::cout << "FragTrap string constructor called!" << std::endl;

	this->hp = 100;
	this->mp = 100;
	this->atk = 30;
}

FragTrap::FragTrap(const FragTrap &f):
	ClapTrap::ClapTrap(f)
{
	std::cout << "FragTrap clone constructor called!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called!" << std::endl;
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

FragTrap	&FragTrap::operator=(const FragTrap &f)
{
	ClapTrap::operator=(f);
	return *this;
}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

void	FragTrap::attack(const std::string &target)
{
	if (!this->mp || this->hp < 1)
	{
		std::cout << "The FragTrap " << this->name << " tried to attack " << target << " but is too weak!" << std::endl;
		return;
	}
	std::cout << "The FragTrap " << this->name << " slaps " << target << " dealing " << this->atk << " damages!" << std::endl;
	this->mp--;
}

void	FragTrap::highFivesGuys(void)
{
	if (!this->mp || this->hp < 1)
	{
		std::cout << this->name << " tried to high fives but is too weak!" << std::endl;
		return;
	}
	std::cout << this->name << " wants an highfives!" << std::endl;
	this->mp--;
}