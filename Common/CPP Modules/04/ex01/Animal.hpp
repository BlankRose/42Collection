/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Animal.hpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 08:26:38 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <string>

class Animal
{
	private:
		std::string		type;

	public:
		Animal();
		Animal(const std::string&);
		Animal(const Animal&);
		~Animal();

		Animal		&operator=(const Animal&);

		void			makeSound(void);
		std::string		getType(void);
};

#endif