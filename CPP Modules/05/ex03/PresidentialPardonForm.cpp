/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - PresidentialPardonForm.cpp        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 17:04:48 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "PresidentialPardonForm.hpp"

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

PRESIDENT::PRESIDENT():
	Form::Form("PresidentialPardonForm", 25, 5)
{
	this->target = "wild";
}

PRESIDENT::PRESIDENT(const std::string &target):
	Form::Form("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

PRESIDENT::PRESIDENT(const PRESIDENT &p):
	Form::Form(p.getName(), p.getMinSign(), p.getMinExec())
{
	if (p.getIsSigned())
		this->beSigned(Bureaucrat("", 1));
	this->target = p.target;
}

PRESIDENT::~PRESIDENT() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

PRESIDENT		&PRESIDENT::operator=(const PRESIDENT &p)
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

void			PRESIDENT::execute(const Bureaucrat &b)
{
	this->checkExec(b);
	std::cout << this->target << " has been forgiven by Zaphod Beeblebrox." << std::endl;
}