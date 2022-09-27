/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Cat.hpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 06:22:35 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat&);
		~Cat();

		Cat		&operator=(const Cat&);	
};

#endif