/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - map.hpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Nov 11 19:07:27 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __MAP_HPP__
# define __MAP_HPP__

#include "tools.hpp"
namespace ft {

	template < class Key, class Type, class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, Type> > >
	class map
	{
		public:
			/////////////// TYPEDEF ////////////////

			typedef Key												key_type;
			typedef Type											mapped_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef ft::pair<const Key, Type>						value_type;

		protected:
			typedef BTree<Key, value_type,
				ft::selector<value_type>, Compare, Allocator>		tree_type;
			typedef tree_type *										tree_pointer;

		public:
			typedef typename tree_type::iterator					iterator;
			typedef typename tree_type::const_iterator				const_iterator;
			typedef typename tree_type::reverse_iterator			reverse_iterator;
			typedef typename tree_type::const_reverse_iterator		const_reverse_iterator;
			typedef typename tree_type::difference_type				difference_type;
			typedef typename tree_type::const_reference				const_reference;
			typedef typename tree_type::const_pointer				const_pointer;
			typedef typename tree_type::reference					reference;
			typedef typename tree_type::size_type					size_type;
			typedef typename tree_type::pointer						pointer;

			///////////// SUB CLASSES //////////////

			class value_compare
			{
				friend class map;

				protected:
					Compare		comp;
					value_compare(Compare c):
						comp(c) {}

				public:
					typedef	bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					bool	operator()(const value_type &lhs, const value_type &rhs) const
						{ return comp(lhs.first, rhs.first); }
			};

			////////////// VARIABLES ///////////////

			tree_type			_tree;

		public:
			///////////// CONSTRUCTORS /////////////

			explicit map(const Compare &cmp = Compare(), const Allocator &alloc = Allocator()):
				_tree(cmp, alloc) {}

			template < class InputIt >
			map(InputIt first, InputIt last, const Compare &cmp = Compare(), const Allocator &alloc = Allocator()):
				_tree(cmp, alloc) { _tree.insert(first, last); }

			map(const map &src):
				_tree(src._tree) {}

			~map() {}

			////////////// OPERATORS ///////////////

			map				&operator=(const map &src) {
				_tree = src._tree;
				return *this;
			}

			mapped_type		&operator[](const key_type &key) {
				iterator	it = lower_bound(key);
				if (it == end() || key_comp()(key, (*it).first))
					it = insert(it, value_type(key, mapped_type()));
				return (*it).second;
			}

			//////////// DATA ACCESSING ////////////

			mapped_type				&at(const key_type &key) {
				iterator		it = lower_bound(key);
				if (it == end() || key_comp()(key, (*it).first))
					throw std::out_of_range("Key not found");
				return (*it).second;
			}

			mapped_type				&at(const key_type &key) const {
				const_iterator	it = lower_bound(key);
				if (it == end() || key_comp()(key, (*it).first))
					throw std::out_of_range("Key not found");
				return (*it).second;
			}

			allocator_type			get_allocator() const { return _tree.get_allocator(); }
			key_compare				key_comp() const { return _tree.key_comp(); }
			value_compare			value_comp() const { return value_compare(key_comp()); }

			bool					empty() const { return _tree.empty(); }
			size_type				size() const { return _tree.size(); }
			size_type				max_size() const { return _tree.max_size(); }

			iterator				begin() { return _tree.begin(); }
			iterator				end() { return _tree.end(); }
			reverse_iterator		rbegin() { return _tree.rbegin(); }
			reverse_iterator		rend() { return _tree.rend(); }

			const_iterator			begin() const { return _tree.begin(); }
			const_iterator			end() const { return _tree.end(); }
			const_reverse_iterator	rbegin() const { return _tree.rbegin(); }
			const_reverse_iterator	rend() const { return _tree.rend(); }

			/////////////// MODIFIERS //////////////

			void					swap(map &src) { _tree.swap(src._tree); }

			ft::pair<iterator, bool>	insert(const value_type &value) { return _tree.insert(value); }
			iterator					insert(iterator pos, const value_type &value) { return _tree.insert(pos, value); }

			template < typename InputIt >
			void						insert(InputIt first, InputIt last) { _tree.insert(first, last); }

			void					erase(iterator pos) { _tree.erase(pos); }
			size_type				erase(const key_type &key) { return _tree.erase(key); }
			void					erase(iterator first, iterator last) { _tree.erase(first, last); }

			void					clear() { _tree.clear(); }

			/////////////// RESEARCH ///////////////

			iterator				find(const key_type &key) { return _tree.find(key); }
			const_iterator			find(const key_type &key) const { return _tree.find(key); }

			iterator				lower_bound(const key_type &key) { return _tree.lower_bound(key); }
			const_iterator			lower_bound(const key_type &key) const { return _tree.lower_bound(key); }

			iterator				upper_bound(const key_type &key) { return _tree.upper_bound(key); }
			const_iterator			upper_bound(const key_type &key) const { return _tree.upper_bound(key); }

			ft::pair<iterator, iterator>				equal_range(const key_type &key) { return _tree.equal_range(key); }
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type &key) const { return _tree.equal_range(key); }

			size_type				count(const key_type &key) const { return _tree.find(key) == _tree.end() ? 0 : 1; }

	};

	////////////// OPERATORS ///////////////

	template < class K, class T, class Comp, class Alloc >
	bool		operator==(const map<K, T, Comp, Alloc> &l, const map<K, T, Comp, Alloc> &r)
		{ return l.size() == r.size() && ft::equal(l.begin(), l.end(), r.begin()); }

	template < class K, class T, class Comp, class Alloc >
	bool		operator!=(const map<K, T, Comp, Alloc> &l, const map<K, T, Comp, Alloc> &r)
		{ return !(l == r); }

	template < class K, class T, class Comp, class Alloc >
	bool		operator<(const map<K, T, Comp, Alloc> &l, const map<K, T, Comp, Alloc> &r)
		{ return ft::lexicographical_compare(l.begin(), l.end(), r.begin(), r.end()); }

	template < class K, class T, class Comp, class Alloc >
	bool		operator>(const map<K, T, Comp, Alloc> &l, const map<K, T, Comp, Alloc> &r)
		{ return r < l; }

	template < class K, class T, class Comp, class Alloc >
	bool		operator>=(const map<K, T, Comp, Alloc> &l, const map<K, T, Comp, Alloc> &r)
		{ return !(l < r); }

	template < class K, class T, class Comp, class Alloc >
	bool		operator<=(const map<K, T, Comp, Alloc> &l, const map<K, T, Comp, Alloc> &r)
		{ return !(r < l); }

}

#endif /* __MAP_HPP__ */