/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - RobotomyRequestForm.cpp           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Jun  1 16:11:59 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "RobotomyRequestForm.hpp"

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

ROBOT::ROBOT():
	Form::Form("RobotomyRequestForm", 75, 45)
{
	this->target = "wild";
}

ROBOT::ROBOT(const std::string &target):
	Form::Form("RobotomyRequestForm", 75, 45)
{
	this->target = target;
}

ROBOT::ROBOT(const ROBOT &p):
	Form::Form(p.getName(), p.getMinSign(), p.getMinExec())
{
	if (p.getIsSigned())
		this->beSigned(Bureaucrat("", 1));
	this->target = p.target;
}

ROBOT::~ROBOT() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

ROBOT		&ROBOT::operator=(const ROBOT &p)
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

void			ROBOT::execute(const Bureaucrat &b)
{
	this->checkExec(b);
	srand(time(NULL));
	std::cout << "* Loud machinery noises *" << std::endl;
	if (rand() % 2 == 1)
		std::cout << this->target << " has been successfully robotized!" << std::endl;
	else
		std::cout << this->target << " robotize didn't went well! :(" << std::endl;
}