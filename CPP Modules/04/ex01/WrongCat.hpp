/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - WrongCat.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue May 31 06:44:03 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat&);
		~WrongCat();

		WrongCat		&operator=(const WrongCat&);	
};

#endif