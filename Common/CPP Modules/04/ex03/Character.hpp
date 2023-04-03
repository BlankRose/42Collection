/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - Character.hpp                   */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 18:41:58 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

#include "AMateria.hpp"
#define CHARACTER_MAX_INV_SIZE 4

class Character:
	public ICharacter
{
	private:
		typedef struct _garbage_collector {
			struct _garbage_collector	*next;
			AMateria					*addr;
		}	_trash;
		_trash *		_del;

		void			addTrash(AMateria *);

	protected:
		std::string		_name;
		AMateria **		_inv;

	public:
		Character();
		Character(const std::string &);
		Character(const Character &);
		~Character();

		Character		&operator=(const Character &);

		virtual const std::string	&getName() const;
		virtual void				equip(AMateria *);
		virtual void				unequip(int);
		virtual void				use(int, ICharacter &);

	protected:
		AMateria **		dupInv() const;
		void			delInv();
};

#endif /* __CHARACTER_HPP__ */