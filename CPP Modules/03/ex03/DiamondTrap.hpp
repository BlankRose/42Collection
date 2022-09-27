/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - DiamondTrap.hpp                   */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 21:40:29 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap: virtual public ScavTrap, virtual public FragTrap
{
	private:
		std::string		name;
	
	public:
		DiamondTrap();
		DiamondTrap(const std::string&);
		DiamondTrap(const DiamondTrap&);
		~DiamondTrap();

		DiamondTrap		&operator=(const DiamondTrap&);

		void		attack(const std::string&);
		void		whoAmI(void);
};

#endif