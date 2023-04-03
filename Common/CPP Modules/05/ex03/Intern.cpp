/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Intern.cpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Jun  1 18:01:05 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Intern.hpp"

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern::~Intern() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Intern	&Intern::operator=(const Intern&) {return *this;}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

Form	*Intern::makeForm(const std::string &name, const std::string &target)
{
	t_forms		forms[] = {
		{"PresidentialPardonForm", new PRESIDENT(target)},
		{"ShrubberyCreationForm", new SHRUB(target)},
		{"RobotomyRequestForm", new ROBOT(target)},
		{"", 0}
	};

	Form	*f = NULL;
	for (int i = 0; forms[i].type; i++) {
		if (forms[i].name == name) f = forms[i].type;
		else delete forms[i].type;
	}

	if (f) std::cout << "Intern creates " << name << std::endl;
	else std::cout << "Intern couldn't find " << name << std::endl;
	return (f);
}