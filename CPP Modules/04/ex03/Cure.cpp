/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - Cure.cpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 18:38:46 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}
Cure::Cure(const Cure &s): AMateria(s._type) {}
Cure::~Cure() {}

Cure		&Cure::operator=(const Cure &s) { _type = s._type; return *this; }

AMateria	*Cure::clone() const { return new Cure(*this); }