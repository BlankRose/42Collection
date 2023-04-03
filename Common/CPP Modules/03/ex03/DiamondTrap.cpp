/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - DiamondTrap.cpp                   */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 22:26:01 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "DiamondTrap.hpp"
#include <iostream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called!" << std::endl;

	ClapTrap::name = "dummy_clap_name";
	this->name = "dummy";
	this->hp = FragTrap::hp;
	this->mp = ScavTrap::mp;
	this->atk = FragTrap::atk;
}

DiamondTrap::DiamondTrap(const std::string &name):
	ClapTrap::ClapTrap(name + "_clap_name"), ScavTrap::ScavTrap(name + "_clap_name"), FragTrap::FragTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap string constructor called!" << std::endl;

	this->name = name;
	this->hp = FragTrap::hp;
	this->mp = ScavTrap::mp;
	this->atk = FragTrap::atk;
}

DiamondTrap::DiamondTrap(const DiamondTrap &f):
	ClapTrap::ClapTrap(f), ScavTrap::ScavTrap(f), FragTrap::FragTrap(f)
{
	std::cout << "DiamondTrap clone constructor called!" << std::endl;
	*this = f;
	ClapTrap::name = f.name + "_clap_name";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called!" << std::endl;
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &f)
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

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << ClapTrap::name << " .. But my TRUE name is " << this->name << " !" << std::endl;
}