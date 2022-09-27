/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Brain.hpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 07:22:55 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include <string>

class Brain
{
	private:
		std::string		*ideas;
	
	public:
		Brain();
		Brain(const Brain&);
		~Brain();

		Brain	&operator=(const Brain&);
};

#endif