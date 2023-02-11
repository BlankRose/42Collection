/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - btree.hpp                       */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Feb  7 17:48:17 CET 2023      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __BTREE_HPP__
# define __BTREE_HPP__

#include "tools.hpp"
namespace ft {

	template <
		typename Key, typename Type, typename Value,
		typename Iterator, typename Const_Iterator,
		typename Compare, typename Allocator = std::allocator<Type>
	>
	class BTree
	{
		private:
			/////////////// TYPEDEF ////////////////

			typedef typename Allocator::template rebind<BTree_Node<Type> >::other	node_allocator;

			typedef BTree_RB *								base_pointer;
			typedef BTree_RB const *						const_base_pointer;
			typedef BTree_Node<Type>						BTree_Node;

		public:
			typedef Key										key_type;
			typedef Type									value_type;
			typedef Allocator								allocator_type;
			typedef value_type *							pointer;
			typedef value_type &							reference;
			typedef BTree_Node *							node_pointer;
			typedef value_type const *						const_pointer;
			typedef value_type const &						const_reference;
			typedef BTree_Node const *						const_node_pointer;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef Iterator								iterator;
			typedef Const_Iterator							const_iterator;
			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

		protected:
			//////////////// MEMORY ////////////////

			template <typename Comp >
			struct BTree_Implementation : public node_allocator
			{
				Comp			key_cmp;
				BTree_RB		top;
				size_type		count;

				BTree_Implementation(node_allocator const &alloc = node_allocator(), Comp const &comp = Comp()):
					node_allocator(alloc), key_cmp(comp), count(0)
				{
					top._color	= RBT_RED;
					top._parent	= nullptr;
					top._left	= &top;
					top._right	= &top;
				}
			};

			BTree_Implementation<Compare> _tree;

			BTree_Node *	_allocate_node() { return _tree.node_allocator::allocate(1); }
			void			_deallocate_node(BTree_Node *p) { _tree.node_allocator::deallocate(p, 1); }

			node_pointer	_construct_node(const value_type &value)
			{
				node_pointer tmp = _allocate_node();
				try {
					get_allocator().construct(&tmp->_value, value);
				} catch (...) {
					_deallocate_node(tmp);
					throw;
				}
				return tmp;
			}

			node_pointer	_dup_node(const_node_pointer node)
			{
				node_pointer	tmp = _construct_node(node->_value);
				tmp->_color	= node->_color;
				tmp->_left	= nullptr;
				tmp->_right	= nullptr;
				return tmp;
			}

			void			_destroy_node(node_pointer ptr)
			{
				get_allocator().destroy(&ptr->_value);
				_deallocate_node(ptr);
			}

		public:
			///////////// CONSTRUCTORS /////////////

			BTree() {}
			BTree(Compare const &cmp) : _tree(allocator_type(), cmp) {}
			BTree(Compare const &cmp, allocator_type const &alloc) : _tree(alloc, cmp) {}
			~BTree() { _erase(_begin()); }

			BTree(BTree const &src)
				: _tree(src.get_allocator(), src._tree.key_cmp)
			{
				if (src._root() != nullptr) {
					_root() = _clone(src._begin(), _end());
					_leftmost() = _min(_root());
					_rightmost() = _max(_root());
					_tree.count = src._tree.count;
				}
			}

			////////////// OPERATORS ///////////////

			BTree		&operator=(BTree const &src) {
				if (this != &src) {
					clear();
					_tree.key_cmp = src._tree.key_cmp;
					if (src._root() != nullptr) {
						_root() = _clone(src._begin(), _end());
						_leftmost() = _min(_root());
						_rightmost() = _max(_root());
						_tree.count = src._tree.count;
					}
				}
				return *this;
			}

			//////////// DATA ACCESSING ////////////

			Compare					key_comp() const { return _tree.key_cmp; }
			allocator_type			get_allocator() const { return *static_cast<node_allocator const *>(&_tree); }
			size_type				size() const { return _tree.count; }
			bool					empty() const { return _tree.count == 0; }

			iterator				begin() { return static_cast<node_pointer>(_tree.top._left); }
			iterator				end() { return static_cast<node_pointer>(&_tree.top); }
			reverse_iterator		rbegin() { return reverse_iterator(end()); }
			reverse_iterator		rend() { return reverse_iterator(begin()); }

			const_iterator			begin() const { return static_cast<const_node_pointer>(_tree.top._left); }
			const_iterator			end() const { return static_cast<const_node_pointer>(&_tree.top); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }
			const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

			size_type 				max_size() const
				{ return std::min<size_type>(_tree.node_allocator::max_size(), std::numeric_limits<difference_type>::max()); }



			////////////// MODIFIERS ///////////////

			pair<iterator, bool>	insert(value_type const &value)
			{
				node_pointer	first = _begin();
				node_pointer	last = _end();
				bool comp = true;
				while (first != nullptr) {
					last = first;
					comp = _tree.key_cmp(Value()(value), _node_key(first));
					first = comp ? _left(first) : _right(first);
				}
				iterator	alt = iterator(last);
				if (comp) {
					if (alt == begin())
						return pair<iterator, bool>(_insert(first, last, value), true);
					else
						--alt;
				}
				if (_tree.key_cmp(_node_key(alt.node), Value()(value)))
					return pair<iterator, bool>(_insert(first, last, value), true);
				return pair<iterator, bool>(alt, false);
			}

			iterator				insert(iterator pos, value_type const &value)
			{
				if (pos.node == _end())
				{
					if (size() > 0 && _tree.key_cmp(_node_key(_rightmost()),
								Value()(value))) {
						return _insert(0, _rightmost(), value);
					}
					return insert(value).first;
				}
				if (_tree.key_cmp(Value()(value), _node_key(pos.node)))
				{
					iterator	before = pos;
					if (pos.node == _leftmost()) {
						return _insert(_leftmost(), _leftmost(), value);
					}
					if (_tree.key_cmp(_node_key((--before).node),
								Value()(value))) {
						if (_right(before.node) == nullptr) {
							return _insert(0, before.node, value);
						}
						return _insert(pos.node, pos.node, value);
					}
					return insert(value).first;
				}
				if (_tree.key_cmp(_node_key(pos.node), Value()(value)))
				{
					iterator	after = pos;
					if (pos.node == _rightmost()) {
						return _insert(0, _rightmost(), value);
					}
					if (_tree.key_cmp(Value()(value),
								_node_key((++after).node))) {
						if (_right(pos.node) == nullptr) {
							return _insert(0, pos.node, value);
						}
						return _insert(after.node, after.node, value);
					}
					return insert(value).first;
				}
				return pos;
			}

			template < typename InputIt >
			void		insert(InputIt first, InputIt last)
			{
				for (; first != last; ++first)
					insert(end(), *first);
			}

			void		erase(iterator position)
			{
				node_pointer y = static_cast<node_pointer>(
					BTree_Handler::BTree_Erase(position.node, _tree.top));
				_destroy_node(y);
				--_tree.count;
			}

			size_type	erase(key_type const &key)
			{
				pair<iterator, iterator> p = equal_range(key);
				size_type n = std::distance(p.first, p.second);
				erase(p.first, p.second);
				return n;
			}

			void		erase(iterator first, iterator last) {
				if (first == begin() && last == end()) {
					clear();
				} else {
					while (first != last) {
						erase(first++);
					}
				}
			}

			void		clear() {
				_erase(_begin());
				_leftmost() = _end();
				_root() = nullptr;
				_rightmost() = _end();
				_tree.count = 0;
			}

			void		swap(BTree &src) {
				if (_root() == nullptr) {
					if (src._root() != nullptr) {
						_root() = src._root();
						_leftmost() = src._leftmost();
						_rightmost() = src._rightmost();
						_root()->_parent = _end();
						src._root() = nullptr;
						src._leftmost() = src._end();
						src._rightmost() = src._end();
					}
				} else if (src._root() == nullptr) {
					src._root() = _root();
					src._leftmost() = _leftmost();
					src._rightmost() = _rightmost();
					src._root()->_parent = src._end();
					_root() = nullptr;
					_leftmost() = _end();
					_rightmost() = _end();
				} else {
					std::swap(_root(), src._root());
					std::swap(_leftmost(), src._leftmost());
					std::swap(_rightmost(), src._rightmost());
					_root()->_parent = _end();
					src._root()->_parent = src._end();
				}
				std::swap(_tree.count, src._tree.count);
				std::swap(_tree.key_cmp, src._tree.key_cmp);
			}

			/////////////// RESEARCH ///////////////

			iterator		find(Key const &key) {
				node_pointer	begin = _begin();
				node_pointer	last = _end();
				while (begin != nullptr) {
					if (!_tree.key_cmp(_node_key(begin), key))
						last = begin, begin = _left(begin);
					else
						begin = _right(begin);
				}
				iterator	alt = iterator(last);
				return (alt == end() || _tree.key_cmp(key, _node_key(alt.node))) ? end() : alt;
			}

			const_iterator	find(Key const &key) const {
				const_node_pointer	begin = _begin();
				const_node_pointer	last = _end();
				while (begin != nullptr) {
					if (!_tree.key_cmp(_node_key(begin), key))
						last = begin, begin = _left(begin);
					else
						begin = _right(begin);
				}
				const_iterator	alt = const_iterator(last);
				return (alt == end() || _tree.key_cmp(key, _node_key(alt.node))) ? end() : alt;
			}

			size_type		count(Key const &key) const {
				pair<const_iterator, const_iterator>	p = equal_range(key);
				const size_type n = std::distance(p.first, p.second);
				return n;
			}

			iterator		lower_bound(Key const &key) {
				node_pointer begin = _begin();
				node_pointer last = _end();
				while (begin != nullptr) {
					if (!_tree.key_cmp(_node_key(begin), key))
						last = begin, begin = _left(begin);
					else
						begin = _right(begin);
				} return iterator(last);
			}

			const_iterator	lower_bound(Key const &key) const {
				const_node_pointer begin = _begin();
				const_node_pointer last = _end();
				while (begin != nullptr) {
					if (!_tree.key_cmp(_node_key(begin), key))
						last = begin, begin = _left(begin);
					else
						begin = _right(begin);
				} return const_iterator(last);
			}

			iterator		upper_bound(Key const &key)
			{
				node_pointer begin = _begin();
				node_pointer last = _end();
				while (begin != nullptr) {
					if (_tree.key_cmp(key, _node_key(begin)))
						last = begin, begin = _left(begin);
					else
						begin = _right(begin);
				} return iterator(last);
			}

			const_iterator	upper_bound(Key const &key) const
			{
				const_node_pointer	begin = _begin();
				const_node_pointer	last = _end();
				while (begin != nullptr) {
					if (_tree.key_cmp(key, _node_key(begin)))
						last = begin, begin = _left(begin);
					else
						begin = _right(begin);
				} return const_iterator(last);
			}

			pair<iterator, iterator>				equal_range(Key const &key)
				{ return pair<iterator, iterator>(lower_bound(key), upper_bound(key)); }

			pair<const_iterator, const_iterator>	equal_range(Key const &key) const
				{ return pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)); }

		private:
			/////////// PRIVATE METHODS ////////////

			iterator _insert(base_pointer node, base_pointer alt, value_type const &value) {
				bool			insert_left = (node != nullptr || alt == _end() || _tree.key_cmp(Value()(value), _node_key(alt)));
				node_pointer	z = _construct_node(value);
				BTree_Handler::BTree_Insert(insert_left, z, alt, _tree.top);
				++_tree.count;
				return iterator(z);
			}

			node_pointer _clone(const_node_pointer node, node_pointer parent) {
				node_pointer top = _dup_node(node);
				top->_parent = parent;
				try {
					if (node->_right)
						top->_right = _clone(_right(node), top);
					parent = top;
					node = _left(node);
					while (node != nullptr) {
						node_pointer	alt = _dup_node(node);
						parent->_left = alt;
						alt->_parent = parent;
						if (node->_right)
							alt->_right = _clone(_right(node), alt);
						parent = alt;
						node = _left(node);
					}
				} catch (...) {
					_erase(top);
					throw;
				}
				return top;
			}

			void _erase(node_pointer node) {
				while (node != nullptr) {
					_erase(_right(node));
					node_pointer y = _left(node);
					_destroy_node(node);
					node = y;
				}
			}

			base_pointer &				_root() { return _tree.top._parent; }
			base_pointer &				_leftmost() { return _tree.top._left; }
			base_pointer &				_rightmost() { return _tree.top._right; }
			node_pointer				_begin() { return static_cast<node_pointer>(_tree.top._parent); }
			node_pointer				_end() { return static_cast<node_pointer>(&_tree.top); }
			static node_pointer			_left(base_pointer node) { return static_cast<node_pointer>(node->_left); }
			static node_pointer			_right(base_pointer node) { return static_cast<node_pointer>(node->_right); }
			static const_reference		_node_value(const_base_pointer node) { return static_cast<const_node_pointer>(node)->_value; }
			static base_pointer			_min(base_pointer ptr) { return BTree_RB::min(ptr); }
			static base_pointer			_max(base_pointer ptr) { return BTree_RB::max(ptr); }
			static Key const &			_node_key(const_base_pointer ptr) { return Value()(_node_value(ptr)); }

			const_base_pointer			_root() const { return _tree.top._parent; }
			const_base_pointer			_leftmost() const { return _tree.top._left; }
			const_base_pointer			_rightmost() const { return _tree.top._right; }
			const_node_pointer			_begin() const { return static_cast<const_node_pointer>(_tree.top._parent); }
			const_node_pointer			_end() const { return static_cast<const_node_pointer>(&_tree.top); }
			static const_node_pointer	_left(const_base_pointer node) { return static_cast<const_node_pointer>(node->_left); }
			static const_node_pointer	_right(const_base_pointer node) { return static_cast<const_node_pointer>(node->_right); }
			static const_reference		_node_value(const_node_pointer node) { return node->_value; }
			static const_base_pointer	_min(const_base_pointer ptr) { return BTree_RB::min(ptr); }
			static const_base_pointer	_max(const_base_pointer ptr) {return BTree_RB::max(ptr); }
			static Key const &			_node_key(const_node_pointer node) { return Value()(_node_value(node)); }
	};

	template <typename T, typename U, typename V, typename It, typename CIt, typename Cmp, typename Alloc>
	bool			operator==(BTree<T, U, V, It, CIt, Cmp, Alloc> const &lhs, BTree<T, U, V, It, CIt, Cmp, Alloc> const &rhs)
		{ return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }

	template <typename T, typename U, typename V, typename It, typename CIt, typename Cmp, typename Alloc>
	bool			operator<(BTree<T, U, V, It, CIt, Cmp, Alloc> const &lhs, BTree<T, U, V, It, CIt, Cmp, Alloc> const &rhs)
		{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

	template <typename T, typename U, typename V, typename It, typename CIt, typename Cmp, typename Alloc>
	bool			operator!=(BTree<T, U, V, It, CIt, Cmp, Alloc> const &lhs, BTree<T, U, V, It, CIt, Cmp, Alloc> const &rhs)
		{ return !(lhs == rhs); }

	template <typename T, typename U, typename V, typename It, typename CIt, typename Cmp, typename Alloc>
	bool			operator>(BTree<T, U, V, It, CIt, Cmp, Alloc> const &lhs, BTree<T, U, V, It, CIt, Cmp, Alloc> const &rhs)
		{ return rhs < lhs; }

	template <typename T, typename U, typename V, typename It, typename CIt, typename Cmp, typename Alloc>
	bool			operator<=(BTree<T, U, V, It, CIt, Cmp, Alloc> const &lhs, BTree<T, U, V, It, CIt, Cmp, Alloc> const &rhs)
		{ return !(rhs < lhs); }

	template <typename T, typename U, typename V, typename It, typename CIt, typename Cmp, typename Alloc>
	bool			operator>=(BTree<T, U, V, It, CIt, Cmp, Alloc> const &lhs, BTree<T, U, V, It, CIt, Cmp, Alloc> const &rhs)
		{ return !(lhs < rhs); }

	template <typename T, typename U, typename V, typename It, typename CIt, typename Cmp, typename Alloc>
	inline void		swap(BTree<T, U, V, It, CIt, Cmp, Alloc> &lhs, BTree<T, U, V, It, CIt, Cmp, Alloc> &rhs)
		{ lhs.swap(rhs); }

}

#endif /* __BTREE_HPP__ */