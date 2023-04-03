/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - pair.hpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Nov  8 15:55:16 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __PAIR_HPP__
# define __PAIR_HPP__

namespace ft
{
	template < class T, class U >
	class pair
	{
		public:
			/////////////// TYPEDEF ////////////////

			typedef T		first_type;
			typedef U		second_type;

			////////////// VARIABLES ///////////////

			first_type		first;
			second_type		second;

			///////////// CONSTRUCTORS /////////////

			pair(): first(first_type()), second(second_type()) {}
			pair(const T &a, const U &b): first(a), second(b) {}
			template < class X, class Y >
			pair(const ft::pair<X, Y> &src): first(T(src.first)), second(U(src.second)) {}
			template < class X, class Y >
			pair(const std::pair<X, Y> &src): first(T(src.first)), second(U(src.second)) {}
			~pair() {}

			////////////// OPERATORS ///////////////

			pair	&operator=(const pair &src) {
				this->first = src.first;
				this->second = src.second;
				return *this;
			}
	};

	template < class T, class U >
	bool			operator==(const pair<T, U> &l, const pair<T, U> &r)
		{ return l.first == r.first && l.second == r.second; }

	template < class T, class U >
	bool			operator!=(const pair<T, U> &l, const pair<T, U> &r)
		{ return !(l == r); }

	template < class T, class U >
	bool			operator<(const pair<T, U> &l, const pair<T, U> &r)
		{ return l.first < r.first || (!(r.first < l.first) && l.second < r.second); }

	template < class T, class U >
	bool			operator>(const pair<T, U> &l, const pair<T, U> &r)
		{ return r < l; }

	template < class T, class U >
	bool			operator>=(const pair<T, U> &l, const pair<T, U> &r)
		{ return !(l < r); }

	template < class T, class U >
	bool			operator<=(const pair<T, U> &l, const pair<T, U> &r)
		{ return !(r < l); }

	template < class T, class U >
	pair<T, U>		make_pair(const T &a, const U &b)
		{ return pair<T, U>(a, b); }
}

#endif