/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - IMateriaSource.hpp              */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 18:47:45 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __IMATERIASOURCE_HPP__
# define __IMATERIASOURCE_HPP__

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {};
		virtual void		learnMateria(AMateria *) = 0;
		virtual AMateria	*createMateria(const std::string &) = 0;
};

#endif /* __IMATERIASOURCE_HPP__ */