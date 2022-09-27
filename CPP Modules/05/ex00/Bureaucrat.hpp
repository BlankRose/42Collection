/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Bureaucrat.hpp                    */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Jun  2 13:22:51 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string		name;
		int						grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string&, const int&);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat();

		//////////////////// METHODS ////////////////////

		Bureaucrat			&operator=(const Bureaucrat&);

		void			gradeUp(void);
		void			gradeDown(void);

		std::string		getName(void);
		std::string		getName(void) const;
		int				getGrade(void);
		int				getGrade(void) const;

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
};

std::ostream	&operator<<(std::ostream&, const Bureaucrat&);

#endif