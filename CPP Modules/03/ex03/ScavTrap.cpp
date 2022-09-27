/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - ScavTrap.cpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 21:12:53 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "ScavTrap.hpp"
#include <iostream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called!" << std::endl;

	this->hp = 100;
	this->mp = 50;
	this->atk = 20;
}

ScavTrap::ScavTrap(const std::string &name):
	ClapTrap::ClapTrap(name)
{
	std::cout << "ScavTrap string constructor called!" << std::endl;

	this->hp = 100;
	this->mp = 50;
	this->atk = 20;
}

ScavTrap::ScavTrap(const ScavTrap &s):
	ClapTrap::ClapTrap(s)
{
	std::cout << "ScavTrap clone constructor called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called!" << std::endl;
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

ScavTrap	&ScavTrap::operator=(const ScavTrap &s)
{
	ClapTrap::operator=(s);
	return *this;
}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

void	ScavTrap::attack(const std::string &target)
{
	if (!this->mp || this->hp < 1)
	{
		std::cout << "The ScavTrap " << this->name << " tried to attack " << target << " but is too weak!" << std::endl;
		return;
	}
	std::cout << "The ScavTrap " << this->name << " rushes at " << target << " dealing " << this->atk << " damages!" << std::endl;
	this->mp--;
}

void	ScavTrap::guardGate(void)
{
	if (!this->mp || this->hp < 1)
	{
		std::cout << this->name << " tried to go into GateKeeper mode but is too weak!" << std::endl;
		return;
	}
	std::cout << this->name << " is now a GateKeeper!" << std::endl;
	this->mp--;
}