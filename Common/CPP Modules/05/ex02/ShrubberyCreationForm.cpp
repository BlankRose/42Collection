/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - ShrubberyCreationForm.cpp         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Jun  1 16:30:22 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

SHRUB::SHRUB():
	Form::Form("ShrubberyCreationForm", 145, 137)
{
	this->target = "wild";
}

SHRUB::SHRUB(const std::string &target):
	Form::Form("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

SHRUB::SHRUB(const SHRUB &p):
	Form::Form(p.getName(), p.getMinSign(), p.getMinExec())
{
	if (p.getIsSigned())
		this->beSigned(Bureaucrat("", 1));
	this->target = p.target;
}

SHRUB::~SHRUB() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

SHRUB		&SHRUB::operator=(const SHRUB &p)
{
	Form::operator=(p);
	return *this;
}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

void			SHRUB::execute(const Bureaucrat &b)
{
	this->checkExec(b);
	std::ofstream	shrub(this->target + "_shrubbery");

	shrub << "   1   " << std::endl
		  << "  111  " << std::endl
		  << "  111  " << std::endl
		  << " 11111 " << std::endl
		  << "   U   " << std::endl;
	shrub.close();
}