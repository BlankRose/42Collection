/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Module 04 - Character.cpp                   */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 19:20:08 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Character.hpp"

static AMateria		**genInv()
{
	AMateria **t = new AMateria*[CHARACTER_MAX_INV_SIZE];
	for (size_t i = 0; i < CHARACTER_MAX_INV_SIZE; i++)
		t[i] = nullptr;
	return t;
}

AMateria			**Character::dupInv() const
{
	AMateria **t = new AMateria*[CHARACTER_MAX_INV_SIZE];
	for (size_t i = 0; i < CHARACTER_MAX_INV_SIZE; i++)
		t[i] = _inv[i];
	return t;
}

void				Character::delInv()
{
	for (size_t i = 0; i < CHARACTER_MAX_INV_SIZE; i++)
		if (_inv[i]) delete _inv[i];
	delete _inv;
}

Character::Character(): _del(nullptr), _name(""), _inv(genInv()) {}
Character::Character(const std::string &n): _del(nullptr), _name(n), _inv(genInv()) {}
Character::Character(const Character &s): _del(nullptr), _name(s._name), _inv(s.dupInv()) {}

Character::~Character()
{
	delInv();
	_trash	*tmp = nullptr;
	for (_trash *it = _del; it != nullptr; it = tmp)
	{ 
		delete it->addr;
		tmp = it->next;
		delete it;
	}
}

void				Character::addTrash(AMateria *addr)
{
	if (!_del) {
		_del = new _trash;
		_del->addr = addr;
		_del->next = nullptr;
	} else {
		_trash	*it = _del;
		while (it->next != nullptr)
			it = it->next;
		it->next = new _trash;
		it->next->addr = addr;
		it->next->next = nullptr;
	}
}

Character			&Character::operator=(const Character &s)
{
	_name = s._name;
	delInv();
	_inv = s.dupInv();
	return *this;
}

const std::string	&Character::getName() const
	{ return _name; }

void				Character::equip(AMateria *m)
{
	for (size_t i = 0; i < CHARACTER_MAX_INV_SIZE; i++) {\
		if (!_inv[i]) {
			_inv[i] = m;
			return;
	}}
}

void				Character::unequip(int i)
{
	if (i >= CHARACTER_MAX_INV_SIZE) return;
	if (_inv[i]) {
		addTrash(_inv[i]);
		_inv[i] = nullptr;
	}
}

void				Character::use(int i, ICharacter &t)
{
	if (i >= CHARACTER_MAX_INV_SIZE) return;
	if (_inv[i])
		_inv[i]->use(t);
}