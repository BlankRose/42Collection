/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Bureaucrat.cpp                    */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Jun  2 13:25:34 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Bureaucrat.hpp"

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Bureaucrat::Bureaucrat(): name("dummy")
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade): name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &f): name(f.name)
{
	this->grade = f.grade;
}

Bureaucrat::~Bureaucrat() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &b)
{
	this->grade = b.grade;
	return *this;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", buraucrat grade " << b.getGrade() << ".";
	return out;
}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */ 
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

std::string	Bureaucrat::getName(void) {return this->name;}
std::string	Bureaucrat::getName(void) const {return this->name;}

int			Bureaucrat::getGrade(void) {return this->grade;}
int			Bureaucrat::getGrade(void) const {return this->grade;}

void		Bureaucrat::gradeUp(void)
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void		Bureaucrat::gradeDown(void)
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void		Bureaucrat::signForm(Form &f)
{
	if (f.getMinSign() < this->grade) {
		std::cout << this->name << " couldn't sign " << f.getName() << ": ";
		throw Form::GradeTooLowException();
	}

	else if (f.getIsSigned()) {
		std::cout << this->name << " couldn't sign " << f.getName() << ": ";
		throw Form::FormAlreadySigned();
	}

	else {
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	}
}