/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - ScavTrap.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 21:21:31 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string&);
		ScavTrap(const ScavTrap&);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap&);
		
		void	attack(const std::string&);
		void	guardGate(void);
};

#endif