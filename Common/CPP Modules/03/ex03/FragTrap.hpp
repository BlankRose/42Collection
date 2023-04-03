/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - FragTrap.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 21:21:26 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"
#include <string>

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string&);
		FragTrap(const FragTrap&);
		~FragTrap();

		FragTrap	&operator=(const FragTrap&);

		void		attack(const std::string&);
		void		highFivesGuys(void);
};

#endif