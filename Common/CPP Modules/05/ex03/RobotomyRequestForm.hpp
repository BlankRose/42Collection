/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - RobotomyRequestForm.hpp           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Jun  1 16:07:29 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

#include "Form.hpp"
#define ROBOT RobotomyRequestForm

class ROBOT: public Form
{
	private:
		std::string		target;

	public:
		ROBOT();
		ROBOT(const std::string&);
		ROBOT(const ROBOT&);
		~ROBOT();

		ROBOT	&operator=(const ROBOT&);

		void	execute(const Bureaucrat&);
};

#endif