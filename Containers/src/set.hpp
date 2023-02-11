/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - set.hpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Feb  7 17:56:24 CET 2023      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __SET_HPP__
# define __SET_HPP__

#include "tools.hpp"
namespace ft {

	template < class Key, class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, Key> > >
	class set
	{
		public:
			/////////////// TYPEDEF ////////////////

			typedef Key												key_type;
			typedef Key												value_type;
			typedef Compare											key_compare;
			typedef Compare											value_compare;
			typedef Allocator										allocator_type;

		protected:
			typedef ft::pair<const Key, Key>						tree_value;
			typedef ft::selector<tree_value>						tree_selector;
			typedef Set_Iterator<tree_value, value_type>			tree_iterator;
			typedef Set_Const_Iterator<tree_value, value_type>		tree_const_iterator;
			typedef BTree<Key, tree_value, tree_selector,
				tree_iterator, tree_const_iterator,
				Compare, Allocator>									tree_type;
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

		private:
			////////////// VARIABLES ///////////////

			tree_type			_tree;

		public:
			///////////// CONSTRUCTORS /////////////

			explicit set(const Compare &cmp = Compare(), const Allocator &alloc = Allocator()):
				_tree(cmp, alloc) {}

			template < class InputIt >
			set(InputIt first, InputIt last, const Compare &cmp = Compare(), const Allocator &alloc = Allocator()):
				_tree(cmp, alloc) { insert(first, last); }

			set(const set &src):
				_tree(src._tree) {}

			~set() {}

			////////////// OPERATORS ///////////////

			set				&operator=(const set &src)
			{
				_tree = src._tree;
				return *this;
			}

			//////////// DATA ACCESSING ////////////

			allocator_type			get_allocator() const	{ return _tree.get_allocator(); }
			key_compare				key_comp() const		{ return _tree.key_comp(); }
			value_compare			value_comp() const		{ return value_compare(key_comp()); }

			bool					empty() const			{ return _tree.empty(); }
			size_type				size() const			{ return _tree.size(); }
			size_type				max_size() const		{ return _tree.max_size(); }

			iterator				begin()					{ return _tree.begin(); }
			iterator				end()					{ return _tree.end(); }
			reverse_iterator		rbegin()				{ return _tree.rbegin(); }
			reverse_iterator		rend()					{ return _tree.rend(); }

			const_iterator			begin() const			{ return _tree.begin(); }
			const_iterator			end() const				{ return _tree.end(); }
			const_reverse_iterator	rbegin() const			{ return _tree.rbegin(); }
			const_reverse_iterator	rend() const			{ return _tree.rend(); }

			/////////////// MODIFIERS //////////////

			void					swap(set &src) { _tree.swap(src._tree); }

			ft::pair<iterator, bool>	insert(const value_type &value) { return _tree.insert(tree_value(value, value)); }
			iterator					insert(iterator pos, const value_type &value) { return _tree.insert(pos, tree_value(value, value)); }

			template < typename InputIt >
			void					insert(InputIt first, InputIt last)
			{
				for (; first != last; ++first)
					_tree.insert(tree_value(*first, *first));
			}

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

	template < class K, class Comp, class Alloc >
	bool		operator==(const set<K, Comp, Alloc> &l, const set<K, Comp, Alloc> &r)
		{ return l.size() == r.size() && ft::equal(l.begin(), l.end(), r.begin()); }

	template < class K, class Comp, class Alloc >
	bool		operator!=(const set<K, Comp, Alloc> &l, const set<K, Comp, Alloc> &r)
		{ return !(l == r); }

	template < class K, class Comp, class Alloc >
	bool		operator<(const set<K, Comp, Alloc> &l, const set<K, Comp, Alloc> &r)
		{ return ft::lexicographical_compare(l.begin(), l.end(), r.begin(), r.end()); }

	template < class K, class Comp, class Alloc >
	bool		operator>(const set<K, Comp, Alloc> &l, const set<K, Comp, Alloc> &r)
		{ return r < l; }

	template < class K, class Comp, class Alloc >
	bool		operator>=(const set<K, Comp, Alloc> &l, const set<K, Comp, Alloc> &r)
		{ return !(l < r); }

	template < class K, class Comp, class Alloc >
	bool		operator<=(const set<K, Comp, Alloc> &l, const set<K, Comp, Alloc> &r)
		{ return !(r < l); }
	
	template < class K, class Comp, class Alloc >
	void		swap(const set<K, Comp, Alloc> &l, const set<K, Comp, Alloc> &r)
		{ l.swap(r); }

}

#endif /* __SET_HPP__ */