/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Form.hpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Jun  2 13:38:10 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __FORM_HPP__
# define __FORM_HPP__

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			sign;
		const int			exec;
		bool				isSigned;

	public:
		Form();
		Form(const std::string&, const int, const int);
		Form(const Form&);
		virtual ~Form() = 0;

		//////////////////// METHODS ////////////////////

		Form			&operator=(const Form&);

		bool			getIsSigned(void);
		int				getMinSign(void);
		int				getMinExec(void);
		std::string		getName(void);

		bool			getIsSigned(void) const;
		int				getMinSign(void) const;
		int				getMinExec(void) const;
		std::string		getName(void) const;
		
		void			beSigned(const Bureaucrat&);
		bool			checkExec(const Bureaucrat&);

		////////////////// EXCEPTIONS ///////////////////

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
					{return "The grade is too low!";}
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
					{return "The grade is too high!";}
		};

		class FormAlreadySigned: public std::exception
		{
			public:
				virtual const char* what() const throw()
					{return "The form is already signed!";}
		};

		class FormExecutionFail: public std::exception
		{
			public:
				virtual const char* what() const throw()
					{return "Conditions to execute form had failed!";}
		};
};

std::ostream	&operator<<(std::ostream&, const Form&);

#endif