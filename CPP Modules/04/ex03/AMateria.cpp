/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - AMateria.cpp                    */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 19:19:45 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type): _type(type) {}
const std::string	&AMateria::getType() const { return _type; }
AMateria::~AMateria() {}

void				AMateria::use(ICharacter &target)
{
	if (_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	if (_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}