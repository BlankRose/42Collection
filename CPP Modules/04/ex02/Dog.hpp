/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Dog.hpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 08:41:46 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*ideas;

	public:
		Dog();
		Dog(const Dog&);
		~Dog();

		Dog		&operator=(const Dog&);
};

#endif