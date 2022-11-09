/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - Cure.hpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 18:36:53 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __CURE_HPP__
# define __CURE_HPP__

#include "AMateria.hpp"

class Cure:
	public AMateria
{
	public:
		Cure();
		Cure(const Cure &);
		~Cure();

		Cure		&operator=(const Cure &);

		virtual AMateria	*clone() const;
};

#endif /* __CURE_HPP__ */