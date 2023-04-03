/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - PresidentialPardonForm.hpp        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 17:01:22 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

#include "Form.hpp"
#define PRESIDENT PresidentialPardonForm

class PRESIDENT: public Form
{
	private:
		std::string		target;

	public:
		PRESIDENT();
		PRESIDENT(const std::string&);
		PRESIDENT(const PRESIDENT&);
		~PRESIDENT();

		PRESIDENT	&operator=(const PRESIDENT&);

		void	execute(const Bureaucrat&);
};

#endif