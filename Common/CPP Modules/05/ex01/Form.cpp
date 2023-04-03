/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Form.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Jun  2 13:37:11 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Form.hpp"

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Form::Form():
	name("dummy"), sign(150), exec(150)
{
	this->isSigned = false;
}

Form::Form(const std::string &name, const int sign, const int exec):
	name(name), sign(sign), exec(exec)
{
	if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
	this->isSigned = false;
}

Form::Form(const Form &f):
	name(f.name), sign(f.sign), exec(f.exec)
{
	this->isSigned = f.isSigned;
}

Form::~Form() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Form			&Form::operator=(const Form &f)
{
	this->isSigned = f.isSigned;
	return *this;
}

std::ostream	&operator<<(std::ostream &out, const Form &f)
{
	out << "Form " << f.getName() << " can be signed from grade " << f.getMinSign()
		<< " and can be executed from grade " << f.getMinExec() << ".";
	return out;
}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

std::string		Form::getName(void) {return this->name;}
int				Form::getMinSign(void) {return this->sign;}
int				Form::getMinExec(void) {return this->exec;}
bool			Form::getIsSigned(void) {return this->isSigned;}

std::string		Form::getName(void) const {return this->name;}
int				Form::getMinSign(void) const {return this->sign;}
int				Form::getMinExec(void) const {return this->exec;}
bool			Form::getIsSigned(void) const {return this->isSigned;}

void		Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->sign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}