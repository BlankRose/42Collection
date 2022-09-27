/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - ClapTrap.cpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 22:35:12 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "ClapTrap.hpp"
#include <iostream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called!" << std::endl;

	this->name = "dummy";
	this->hp = 10;
	this->mp = 10;
	this->atk = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap string constructor called!" << std::endl;

	this->name = name;
	this->hp = 10;
	this->mp = 10;
	this->atk = 0;
}

ClapTrap::ClapTrap(const ClapTrap &t)
{
	std::cout << "ClapTrap clone constructor called!" << std::endl;

	this->name = t.name;
	this->hp = t.hp;
	this->mp = t.mp;
	this->atk = t.atk;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called!" << std::endl;
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

ClapTrap	&ClapTrap::operator=(const ClapTrap &t)
{
	this->name = t.name;
	this->hp = t.hp;
	this->mp = t.mp;
	this->atk = t.atk;

	return *this;
}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

void	ClapTrap::attack(const std::string &target)
{
	if (!this->mp || this->hp < 1)
	{
		std::cout << "The ClapTrap " << this->name << " tried to attack " << target << " but is running out of energy!" << std::endl;
		return;
	}
	std::cout << "The ClapTrap " << this->name << " attacks " << target << " dealing " << this->atk << " damages!" << std::endl;
	this->mp--;
}

void	ClapTrap::attack(ClapTrap &target)
{
	this->attack(target.name);
	target.takeDamage(this->atk);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)(this->hp - amount) < 0) this->hp = 0;
	else this->hp -= amount;
	std::cout << "The ClapTrap " << this->name << " took " << amount << " damages! (" << this->hp << "Hp remaining)" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->mp || this->hp < 1) 
	{
		std::cout << this->name << " tried to heal but is running out of energy!" << std::endl;
		return;
	}
	this->hp += amount;
	std::cout << this->name << " healed " << amount << " hp! (" << this->hp << "Hp remaining)" << std::endl;
	this->mp--;
}