/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - Ice.hpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 18:33:34 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __ICE_HPP__
# define __ICE_HPP__

#include "AMateria.hpp"

class Ice:
	public AMateria
{
	public:
		Ice();
		Ice(const Ice &);
		~Ice();

		Ice		&operator=(const Ice &);

		virtual AMateria	*clone() const;
};

#endif /* __ICE_HPP__ */