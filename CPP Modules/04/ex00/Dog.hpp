/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Dog.hpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 06:19:45 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog&);
		~Dog();

		Dog		&operator=(const Dog&);	
};

#endif