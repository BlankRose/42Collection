/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - tools.hpp                       */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Nov 11 19:07:05 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __TOOLS_HPP__
# define __TOOLS_HPP__

namespace ft {

/* ********************************* */
/*                                   */
/*         ITERATORS TRAITS          */
/*                                   */
/* ********************************* */

	struct		random_access_iterator_tag {};
	struct		bidirectional_iterator_tag {};

	template < class Iterator >
	class iterators_traits
	{
		public:
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::reference			reference;
			typedef void									pointer;
	};

/* ********************************* */
/*                                   */
/*             ENABLE IF             */
/*                                   */
/* ********************************* */

	template < bool B, class Type = void >
	struct enable_if{};

	template < class Type >
	struct enable_if<true, Type> {
		typedef Type	type;
	};

/* ********************************* */
/*                                   */
/*            IS INTEGRAL            */
/*                                   */
/* ********************************* */

// NON INTEGRAL

	template < class Type >
	struct is_integral { static const bool value = false; };

// SIGNED INTEGRALS

	template <> struct is_integral<char> { static const bool value = true; };
	template <> struct is_integral<short> { static const bool value = true; };
	template <> struct is_integral<int> { static const bool value = true; };
	template <> struct is_integral<long> { static const bool value = true; };
	template <> struct is_integral<long long> { static const bool value = true; };

// UNSIGNED INTEGRALS

	template <> struct is_integral<unsigned char> { static const bool value = true; };
	template <> struct is_integral<unsigned short> { static const bool value = true; };
	template <> struct is_integral<unsigned int> { static const bool value = true; };
	template <> struct is_integral<unsigned long> { static const bool value = true; };
	template <> struct is_integral<unsigned long long> { static const bool value = true; };

// SPECIAL INTEGRALS

	template <> struct is_integral<bool> { static const bool value = true; };
	template <> struct is_integral<char16_t> { static const bool value = true; };
	template <> struct is_integral<char32_t> { static const bool value = true; };
	template <> struct is_integral<wchar_t> { static const bool value = true; };

/* ********************************* */
/*                                   */
/*      LEXICOGRAPHICAL COMPARE      */
/*                                   */
/* ********************************* */

	template < class InputIt1, class InputIt2 >
	bool	lexicographical_compare(InputIt1 beginA, InputIt1 endA, InputIt2 beginB, InputIt2 endB) {
		for (; (beginA != endA) && (beginB != endB); ++beginA, ++beginB) {
			if (*beginA < *beginB) return true;
			if (*beginB < *beginA) return false;
		}
		return (beginA == endA) && (beginB != endB);
	}

	template < class InputIt1, class InputIt2, class Compare >
	bool	lexicographical_compare(InputIt1 beginA, InputIt1 endA, InputIt2 beginB, InputIt2 endB, Compare cmp) {
		for (; (beginA != endA) && (beginB != endB); ++beginA, ++beginB) {
			if (cmp(*beginB, *beginA)) return false;
			if (cmp(*beginA, *beginB)) return true;
		}
		return (beginA == endA) && (beginB != endB);
	}

	template < class InputIt1, class InputIt2 >
	bool	equal(InputIt1 beginA, InputIt1 endA, InputIt2 beginB) {
		for (; (beginA != endA); ++beginA, ++beginB)
			if (*beginA != *beginB) return false;
		return true;
	}

	template < class InputIt1, class InputIt2, class Compare >
	bool	equal(InputIt1 beginA, InputIt1 endA, InputIt2 beginB, Compare cmp) {
		for (; (beginA != endA); ++beginA, ++beginB)
			if (!cmp(*beginA, *beginB)) return false;
		return true;
	}

/* ********************************* */
/*                                   */
/*               EXTRAS              */
/*                                   */
/* ********************************* */

	template <class P >
	struct selector
	{
		typedef P						argument_type;
		typedef typename P::first_type	result_type;

		result_type const &operator()(P const &__x) const 
			{ return __x.first; }
	};

/* ********************************* */
/*                                   */
/*      VARIOUS NEEDED INCLUDES      */
/*                                   */
/* ********************************* */

}

#include <algorithm>
#include <stdexcept>
#include <limits>

#include "pair.hpp"
#include "btree_node.hpp"
#include "iterators.hpp"
#include "btree.hpp"

#endif /* __TOOLS_HPP__ */
