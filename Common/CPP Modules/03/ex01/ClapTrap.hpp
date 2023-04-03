/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - ClapTrap.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon May 30 19:13:41 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

#include <string>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hp;
		unsigned int	mp;
		unsigned int	atk;
	
	public:
		ClapTrap();
		ClapTrap(std::string);
		ClapTrap(const ClapTrap&);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap&);

		void	attack(const std::string&);
		void	takeDamage(unsigned int);
		void	beRepaired(unsigned int);
};

#endif