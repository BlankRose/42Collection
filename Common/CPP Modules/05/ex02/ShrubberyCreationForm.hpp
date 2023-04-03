/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - ShrubberyCreationForm.hpp         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Jun  1 16:09:46 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

#include "Form.hpp"
#define SHRUB ShrubberyCreationForm

class SHRUB: public Form
{
	private:
		std::string		target;

	public:
		SHRUB();
		SHRUB(const std::string&);
		SHRUB(const SHRUB&);
		~SHRUB();

		SHRUB	&operator=(const SHRUB&);

		void	execute(const Bureaucrat&);
};

#endif