/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - Ice.cpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 18:38:51 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}
Ice::Ice(const Ice &s): AMateria(s._type) {}
Ice::~Ice() {}

Ice			&Ice::operator=(const Ice &s) { _type = s._type; return *this; }

AMateria	*Ice::clone() const { return new Ice(*this); }