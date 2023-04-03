/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - MateriaSource.cpp               */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 19:20:12 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "MateriaSource.hpp"

static AMateria		**genInv()
{
	AMateria **t = new AMateria*[SOURCE_MAX_INV_SIZE];
	for (size_t i = 0; i < SOURCE_MAX_INV_SIZE; i++)
		t[i] = nullptr;
	return t;
}

AMateria			**MateriaSource::dupInv() const
{
	AMateria **t = new AMateria*[SOURCE_MAX_INV_SIZE];
	for (size_t i = 0; i < SOURCE_MAX_INV_SIZE; i++)
		t[i] = _inv[i];
	return t;
}

void				MateriaSource::delInv()
{
	for (size_t i = 0; i < SOURCE_MAX_INV_SIZE; i++)
		if (_inv[i]) delete _inv[i];
	delete _inv;
}

MateriaSource::MateriaSource(): _inv(genInv()) {}
MateriaSource::MateriaSource(const MateriaSource &s): _inv(s.dupInv()) {}
MateriaSource::~MateriaSource() { delInv(); }

MateriaSource		&MateriaSource::operator=(const MateriaSource &s)
	{ delInv(); _inv = s.dupInv(); return *this; }

void				MateriaSource::learnMateria(AMateria *s)
{
	for (size_t i = 0; i < SOURCE_MAX_INV_SIZE; i++) {
		if (!_inv[i]) {
			_inv[i] = s->clone();
			return;
	}}
}

AMateria			*MateriaSource::createMateria(const std::string &type)
{
	for (size_t i = 0; i < SOURCE_MAX_INV_SIZE; i++)
		if (_inv[i] && _inv[i]->getType() == type)
			return _inv[i]->clone();
	return nullptr;
}