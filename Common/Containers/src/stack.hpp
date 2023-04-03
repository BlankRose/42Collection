/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - stack.hpp                       */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Feb  7 15:40:46 CET 2023      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __STACK_HPP__
# define __STACK_HPP__

#include "vector.hpp"
namespace ft {

	template < class Type, class Container = ft::vector<Type> >
	class stack
	{
		public:
			/////////////// TYPEDEF ////////////////

    		typedef Container									container_type;
    		typedef typename container_type::value_type			value_type;
    		typedef typename container_type::size_type			size_type;

		protected:
			////////////// VARIABLES ///////////////

			container_type		c;

		public:
			///////////// CONSTRUCTORS /////////////

			explicit stack(const container_type &ctnr = container_type()): c(ctnr) {}
			~stack() {}

			/////////////// METHODS ////////////////

			bool				empty(void) const				{ return c.empty(); }
			size_type			size(void) const				{ return c.size(); }
			value_type			&top(void)						{ return c.back(); }
			const value_type	&top(void) const				{ return c.back(); }
			void				push(const value_type &value)	{ c.push_back(value); }
			void				pop(void)						{ c.pop_back(); }

			////////////// OPERATORS ///////////////

			template < class T, class C >
			friend bool			operator<(const stack<T, C> &ref, const stack<T, C> &cmp);

	};

	template < class Type, class Container >
	bool		operator==(const stack<Type, Container> &l, const stack<Type, Container> &r)
		{ return !(l < r || r < l); }

	template < class Type, class Container >
	bool		operator!=(const stack<Type, Container> &l, const stack<Type, Container> &r)
		{ return !(l == r); }

	template < class Type, class Container >
	bool		operator<(const stack<Type, Container> &l, const stack<Type, Container> &r)
		{ return l.c < r.c; }

	template < class Type, class Container >
	bool		operator>(const stack<Type, Container> &l, const stack<Type, Container> &r)
		{ return r < l; }

	template < class Type, class Container >
	bool		operator>=(const stack<Type, Container> &l, const stack<Type, Container> &r)
		{ return !(l < r); }

	template < class Type, class Container >
	bool		operator<=(const stack<Type, Container> &l, const stack<Type, Container> &r)
		{ return !(r < l); }

}

#endif