/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - MutantStack.hpp                   */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun  5 12:56:23 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

#include <iostream>
#include <stack>

template <class T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack() {return ;}
		MutantStack(const MutantStack &m) {*this = m;}
		~MutantStack() {return ;}

		MutantStack		&operator=(const MutantStack &m) {
			this->c = m.c;
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator		begin(void) {return this->c.begin();};
		iterator		end(void) {return this->c.end();};
};

#endif