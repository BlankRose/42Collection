/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Intern.hpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Jun  1 16:50:47 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

#include "header.hpp"

class Intern
{
	public:
		typedef struct s_formList {
			std::string		name;
			Form			*type;
		}	t_forms;

	public:
		Intern();
		Intern(const Intern&);
		~Intern();

		Intern	&operator=(const Intern&);

		Form	*makeForm(const std::string &, const std::string &);
};

#endif