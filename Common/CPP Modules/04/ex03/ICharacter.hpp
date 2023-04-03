/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - ICharacter.hpp                  */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 17:24:12 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __ICHARACTER_HPP__
# define __ICHARACTER_HPP__

#include <string>
class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual const std::string	&getName() const = 0;
		virtual void				equip(AMateria *m) = 0;
		virtual void				unequip(int index) = 0;
		virtual void				use(int index, ICharacter &target) = 0;
};

#endif /* __ICHARACTER_HPP__ */