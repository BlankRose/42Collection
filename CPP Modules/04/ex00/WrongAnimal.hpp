/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - WrongAnimal.hpp                   */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 06:42:38 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

#include <string>

class WrongAnimal
{
	private:
		std::string		type;

	public:
		WrongAnimal();
		WrongAnimal(const std::string&);
		WrongAnimal(const WrongAnimal&);
		~WrongAnimal();

		WrongAnimal		&operator=(const WrongAnimal&);

		void			makeSound(void);
		std::string		getType(void);
};

#endif