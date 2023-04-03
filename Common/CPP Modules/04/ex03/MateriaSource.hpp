/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - MateriaSource.hpp               */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 18:50:39 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"
#define SOURCE_MAX_INV_SIZE 4

class MateriaSource:
	public IMateriaSource
{
	protected:
		AMateria **		_inv;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &);
		~MateriaSource();

		MateriaSource		&operator=(const MateriaSource &);

		virtual void		learnMateria(AMateria *);
		virtual AMateria	*createMateria(const std::string &);

	private:
		AMateria **		dupInv() const;
		void			delInv();
};

#endif /* __MATERIASOURCE_HPP__ */