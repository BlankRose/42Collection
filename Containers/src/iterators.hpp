/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - iterators.hpp                   */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Feb  7 18:11:53 CET 2023      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __ITERATORS_HPP__
# define __ITERATORS_HPP__

#include "btree_node.hpp"
namespace ft {

	template < class Iterator >
	class reverse_iterator;

/* ********************************* */
/*                                   */
/*      RANDOM ACCESS ITERATOR       */
/*                                   */
/* ********************************* */

	template < class Type >
	class random_access_iterator
	{
		public:
			/////////////// TYPEDEF ////////////////

			typedef random_access_iterator_tag		iterator_category;
			typedef std::ptrdiff_t					difference_type;
			typedef Type							value_type;
			typedef Type &							reference;
			typedef Type *							pointer;

		private:
			////////////// VARIABLES ///////////////

			pointer		_ptr;

		public:
			///////////// CONSTRUCTORS /////////////

			random_access_iterator(): _ptr(nullptr) {}
			random_access_iterator(pointer ptr): _ptr(ptr) {}

			template < class T >
			random_access_iterator(const random_access_iterator<T> &src): _ptr(src.base()) {}
			template < class T >
			random_access_iterator(const reverse_iterator<T> &src): _ptr(src.base()) {}

			virtual ~random_access_iterator() {}

			pointer			base() const { return _ptr; }

			////////////// OPERATORS ///////////////

			random_access_iterator	&operator=(const random_access_iterator &src) {
				this->_ptr = src._ptr;
				return *this;
			}

			/////////////// FORWARD ////////////////

			random_access_iterator	&operator++(void) {
				this->_ptr++;
				return *this;
			}

			random_access_iterator	operator++(int) {
				random_access_iterator tmp(*this);
				this->_ptr++;
				return tmp;
			}

			random_access_iterator	&operator+=(const difference_type &n)
				{ this->_ptr += n; return *this; }

			random_access_iterator	operator+(const difference_type &n) const
				{ return random_access_iterator(this->_ptr + n); }

			/////////////// BACKWARD ///////////////

			random_access_iterator	&operator--(void) {
				this->_ptr--;
				return *this;
			}

			random_access_iterator	operator--(int) {
				random_access_iterator tmp(*this);
				this->_ptr--;
				return tmp;
			}

			random_access_iterator	&operator-=(const difference_type &n)
				{ this->_ptr -= n; return *this; }

			random_access_iterator	operator-(const difference_type &n) const
				{ return random_access_iterator(this->_ptr - n); }

			/////////////// SPECIALS ///////////////

			reference		operator*(void) const						{ return *(this->_ptr); }
			pointer			operator->(void) const						{ return &(operator*()); }
			reference		operator[](const difference_type &n) const	{ return *(operator+(n)); }
	};

	///////////// INTERMEDIATE /////////////

	template < typename T >
	random_access_iterator<T>		operator+(const typename random_access_iterator<T>::difference_type &n, const random_access_iterator<T> &s)
		{ return random_access_iterator<T>(s.base() + n); }

	template < typename T >
	random_access_iterator<T>		operator-(const typename random_access_iterator<T>::difference_type &n, const random_access_iterator<T> &s)
		{ return random_access_iterator<T>(s.base() - n); }

	template < typename TL, typename TR >
	typename random_access_iterator<TL>::difference_type
		operator+(const random_access_iterator<TL> &l, const random_access_iterator<TR> &r)
		{ return l.base() + r.base(); }

	template < typename TL, typename TR >
	typename random_access_iterator<TL>::difference_type
		operator-(const random_access_iterator<TL> &l, const random_access_iterator<TR> &r)
		{ return l.base() - r.base(); }

	////////////// CONDITIONS //////////////

	template < typename TL, typename TR >
	bool			operator==(const random_access_iterator<TL> &l, const random_access_iterator<TR> &r)
		{ return l.base() == r.base(); }

	template < typename TL, typename TR >
	bool			operator!=(const random_access_iterator<TL> &l, const random_access_iterator<TR> &r)
		{ return l.base() != r.base(); }

	template < typename TL, typename TR >
	bool			operator>=(const random_access_iterator<TL> &l, const random_access_iterator<TR> &r)
		{ return l.base() >= r.base(); }

	template < typename TL, typename TR >
	bool			operator<=(const random_access_iterator<TL> &l, const random_access_iterator<TR> &r)
		{ return l.base() <= r.base(); }

	template < typename TL, typename TR >
	bool			operator>(const random_access_iterator<TL> &l, const random_access_iterator<TR> &r)
		{ return l.base() > r.base(); }

	template < typename TL, typename TR >
	bool			operator<(const random_access_iterator<TL> &l, const random_access_iterator<TR> &r)
		{ return l.base() < r.base(); }

	//////////// RAW CONDITIONS ////////////

	template < typename T >
	bool			operator==(const random_access_iterator<T> &l, const typename random_access_iterator<T>::pointer &r)
		{ return r == l.base(); }

	template < typename T >
	bool			operator!=(const random_access_iterator<T> &l, const typename random_access_iterator<T>::pointer &r)
		{ return r != l.base(); }

	template < typename T >
	bool			operator>=(const random_access_iterator<T> &l, const typename random_access_iterator<T>::pointer &r)
		{ return r >= l.base(); }

	template < typename T >
	bool			operator<=(const random_access_iterator<T> &l, const typename random_access_iterator<T>::pointer &r)
		{ return r <= l.base(); }

	template < typename T >
	bool			operator>(const random_access_iterator<T> &l, const typename random_access_iterator<T>::pointer &r)
		{ return r > l.base(); }

	template < typename T >
	bool			operator<(const random_access_iterator<T> &l, const typename random_access_iterator<T>::pointer &r)
		{ return r < l.base(); }

	template < typename T >
	bool			operator==(const typename random_access_iterator<T>::pointer &r, const random_access_iterator<T> &l)
		{ return r == l.base(); }

	template < typename T >
	bool			operator!=(const typename random_access_iterator<T>::pointer &r, const random_access_iterator<T> &l)
		{ return r != l.base(); }

	template < typename T >
	bool			operator>=(const typename random_access_iterator<T>::pointer &r, const random_access_iterator<T> &l)
		{ return r >= l.base(); }

	template < typename T >
	bool			operator<=(const typename random_access_iterator<T>::pointer &r, const random_access_iterator<T> &l)
		{ return r <= l.base(); }

	template < typename T >
	bool			operator>(const typename random_access_iterator<T>::pointer &r, const random_access_iterator<T> &l)
		{ return r > l.base(); }

	template < typename T >
	bool			operator<(const typename random_access_iterator<T>::pointer &r, const random_access_iterator<T> &l)
		{ return r < l.base(); }



/* ********************************* */
/*                                   */
/*      BIDIRECTIONAL ITERATOR       */
/*                                   */
/* ********************************* */

	template < typename T >
	struct BTree_Const_Iterator;

	template < typename T >
	struct BTree_Iterator
	{
		/////////////// TYPEDEF ////////////////

		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T &									reference;
		typedef T *									pointer;

		typedef BTree_Iterator<T>					iterator;
		typedef BTree_Const_Iterator<T>				const_iterator;
		typedef BTree_RB::base_pointer				base_pointer;
		typedef BTree_Node<T> *						node_pointer;

		////////////// VARIABLES ///////////////

		base_pointer node;
		
		///////////// CONSTRUCTORS /////////////

		BTree_Iterator() : node() {}
		BTree_Iterator(node_pointer x) : node(x) {}

		/////////////// FORWARD ////////////////

		iterator 		&operator++() {
			node = BTree_Handler::BTree_Forward(node);
			return *this;
		}

		iterator 		operator++(int) {
			iterator tmp = *this;
			node = BTree_Handler::BTree_Forward(node);
			return tmp;
		}

		/////////////// BACKWARD ///////////////

		iterator 		&operator--() {
			node = BTree_Handler::BTree_Backward(node);
			return *this;
		}

		iterator 		operator--(int) {
			iterator tmp = *this;
			node = BTree_Handler::BTree_Backward(node);
			return tmp;
		}

		/////////////// SPECIALS ///////////////

		reference		operator*() const { return static_cast<node_pointer>(node)->_value; }
		pointer			operator->() const { return &static_cast<node_pointer>(node)->_value; }

	};

	template < typename T >
	struct BTree_Const_Iterator
	{
		/////////////// TYPEDEF ////////////////

		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef std::ptrdiff_t						difference_type;
		typedef const T								value_type;
		typedef const T &							reference;
		typedef const T *							pointer;

		typedef BTree_Iterator<T>					iterator;
		typedef BTree_Const_Iterator<T>				const_iterator;
		typedef BTree_RB::const_base_pointer		base_pointer;
		typedef const BTree_Node<T> *				node_pointer;

		////////////// VARIABLES ///////////////

		base_pointer								node;
		
		///////////// CONSTRUCTORS /////////////

		BTree_Const_Iterator() : node() {}
		BTree_Const_Iterator(node_pointer x) : node(x) {}
		BTree_Const_Iterator(iterator const &it) : node(it.node) {}

		/////////////// FORWARD ////////////////

		const_iterator		&operator++() {
			node = BTree_Handler::BTree_Forward(node);
			return *this;
		}

		const_iterator		operator++(int) {
			const_iterator tmp = *this;
			node = BTree_Handler::BTree_Forward(node);
			return tmp;
		}

		/////////////// BACKWARD ///////////////

		const_iterator		&operator--() {
			node = BTree_Handler::BTree_Backward(node);
			return *this;
		}

		const_iterator		operator--(int) {
			const_iterator tmp = *this;
			node = BTree_Handler::BTree_Backward(node);
			return tmp;
		}

		/////////////// SPECIALS ///////////////

		reference			operator*() const { return static_cast<node_pointer>(node)->_value; }
		pointer				operator->() const { return &static_cast<node_pointer>(node)->_value; }

	};

	////////////// CONDITIONS //////////////

	template < typename T >
	bool	operator==(const BTree_Iterator<T> &lhs, const BTree_Iterator<T> &rhs)
		{ return lhs.node == rhs.node; }

	template < typename T >
	bool	operator!=(const BTree_Iterator<T> &lhs, const BTree_Iterator<T> &rhs)
		{ return lhs.node != rhs.node; }

	template < typename T >
	bool		operator==(const BTree_Const_Iterator<T> &lhs, const BTree_Const_Iterator<T> &rhs)
		{ return lhs.node == rhs.node; }

	template < typename T >
	bool		operator!=(const BTree_Const_Iterator<T> &lhs, const BTree_Const_Iterator<T> &rhs)
		{ return !(lhs == rhs); }

	template < typename T >
	bool		operator==(const BTree_Const_Iterator<T> &lhs, const BTree_Iterator<T> &rhs)
		{ return lhs.node == rhs.node; }

	template < typename T >
	bool		operator!=(const BTree_Const_Iterator<T> &lhs, const BTree_Iterator<T> &rhs)
		{ return !(lhs == rhs); }



/* ********************************* */
/*                                   */
/*           SET ITERATOR            */
/*                                   */
/* ********************************* */

	template < typename T, typename V >
	struct Set_Const_Iterator;

	template < typename T, typename V >
	struct Set_Iterator
	{
		/////////////// TYPEDEF ////////////////

		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef std::ptrdiff_t						difference_type;
		typedef const V								value_type;
		typedef const V &							reference;
		typedef const V *							pointer;

		typedef Set_Iterator<T, V>					iterator;
		typedef Set_Const_Iterator<T, V>			const_iterator;
		typedef BTree_RB::base_pointer				base_pointer;
		typedef BTree_Node<T> *						node_pointer;

		////////////// VARIABLES ///////////////

		base_pointer node;

		///////////// CONSTRUCTORS /////////////

		Set_Iterator() : node() {}
		Set_Iterator(node_pointer x) : node(x) {}
		Set_Iterator(const Set_Const_Iterator<T, V> &it)
			{ node = (node_pointer) it.node; (void) it; }

		/////////////// FORWARD ////////////////

		iterator 		&operator++() {
			node = BTree_Handler::BTree_Forward(node);
			return *this;
		}

		iterator 		operator++(int) {
			iterator tmp = *this;
			node = BTree_Handler::BTree_Forward(node);
			return tmp;
		}

		/////////////// BACKWARD ///////////////

		iterator 		&operator--() {
			node = BTree_Handler::BTree_Backward(node);
			return *this;
		}

		iterator 		operator--(int) {
			iterator tmp = *this;
			node = BTree_Handler::BTree_Backward(node);
			return tmp;
		}

		/////////////// SPECIALS ///////////////

		reference		operator*() const { return static_cast<node_pointer>(node)->_value.second; }
		pointer			operator->() const { return &static_cast<node_pointer>(node)->_value.second; }

	};

	template < typename T, typename V >
	struct Set_Const_Iterator
	{
		/////////////// TYPEDEF ////////////////

		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef std::ptrdiff_t						difference_type;
		typedef const V								value_type;
		typedef const V &							reference;
		typedef const V *							pointer;

		typedef Set_Iterator<T, V>					iterator;
		typedef Set_Const_Iterator<T, V>			const_iterator;
		typedef BTree_RB::const_base_pointer		base_pointer;
		typedef const BTree_Node<T> *				node_pointer;

		////////////// VARIABLES ///////////////

		base_pointer								node;

		///////////// CONSTRUCTORS /////////////

		Set_Const_Iterator() : node() {}
		Set_Const_Iterator(node_pointer x) : node(x) {}
		Set_Const_Iterator(iterator const &it) : node(it.node) {}

		/////////////// FORWARD ////////////////

		const_iterator		&operator++() {
			node = BTree_Handler::BTree_Forward(node);
			return *this;
		}

		const_iterator		operator++(int) {
			const_iterator tmp = *this;
			node = BTree_Handler::BTree_Forward(node);
			return tmp;
		}

		/////////////// BACKWARD ///////////////

		const_iterator		&operator--() {
			node = BTree_Handler::BTree_Backward(node);
			return *this;
		}

		const_iterator		operator--(int) {
			const_iterator tmp = *this;
			node = BTree_Handler::BTree_Backward(node);
			return tmp;
		}

		/////////////// SPECIALS ///////////////

		reference			operator*() const { return static_cast<node_pointer>(node)->_value.second; }
		pointer				operator->() const { return &static_cast<node_pointer>(node)->_value.second; }

	};

	////////////// CONDITIONS //////////////

	template < typename T, typename V >
	bool	operator==(const Set_Iterator<T, V> &lhs, const Set_Iterator<T, V> &rhs)
		{ return lhs.node == rhs.node; }

	template < typename T, typename V >
	bool	operator!=(const Set_Iterator<T, V> &lhs, const Set_Iterator<T, V> &rhs)
		{ return lhs.node != rhs.node; }

	template < typename T, typename V >
	bool		operator==(const Set_Const_Iterator<T, V> &lhs, const Set_Const_Iterator<T, V> &rhs)
		{ return lhs.node == rhs.node; }

	template < typename T, typename V >
	bool		operator!=(const Set_Const_Iterator<T, V> &lhs, const Set_Const_Iterator<T, V> &rhs)
		{ return !(lhs == rhs); }

	template < typename T, typename V >
	bool		operator==(const Set_Const_Iterator<T, V> &lhs, const Set_Iterator<T, V> &rhs)
		{ return lhs.node == rhs.node; }

	template < typename T, typename V >
	bool		operator!=(const Set_Const_Iterator<T, V> &lhs, const Set_Iterator<T, V> &rhs)
		{ return !(lhs == rhs); }



/* ********************************* */
/*                                   */
/*         REVERSE ITERATOR          */
/*                                   */
/* ********************************* */

	template < class Iterator >
	class reverse_iterator
	{
		public:
			/////////////// TYPEDEF ////////////////

			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::pointer				pointer;

		private:
			////////////// VARIABLES ///////////////

			Iterator		_it;

		public:
			///////////// CONSTRUCTORS /////////////

			reverse_iterator(): _it(Iterator()) {}
			reverse_iterator(pointer ptr): _it(Iterator(ptr)) {}
			template < class Iter >
			reverse_iterator(const Iter &src): _it(Iterator(src)) {}
			template < class T >
			reverse_iterator(const reverse_iterator<T> &src): _it(src.base()) {}
			virtual ~reverse_iterator() {}

			pointer					base() const { return _it.base(); }

			////////////// OPERATORS ///////////////

			reverse_iterator		&operator=(const reverse_iterator &src) {
				_it = src._it;
				return *this;
			}

			/////////////// FORWARD ////////////////

			reverse_iterator		&operator++(void) {
				_it--;
				return *this;
			}

			reverse_iterator		operator++(int) {
				reverse_iterator tmp(*this);
				_it--;
				return tmp;
			}

			reverse_iterator		&operator+=(const difference_type &n)
				{ _it -= n; return *this; }

			reverse_iterator		operator+(const difference_type &n) const
				{ return reverse_iterator(_it - n); }

			/////////////// BACKWARD ///////////////

			reverse_iterator		&operator--(void) {
				_it++;
				return *this;
			}

			reverse_iterator		operator--(int) {
				reverse_iterator tmp(*this);
				_it++;
				return tmp;
			}

			reverse_iterator		&operator-=(const difference_type &n)
				{ _it += n; return *this; }

			reverse_iterator		operator-(const difference_type &n) const
				{ return reverse_iterator(_it + n); }

			/////////////// SPECIALS ///////////////

			reference		operator*(void) const						{ Iterator tmp(_it); return *(--tmp); }
			pointer			operator->(void) const						{ return &(operator*()); }
			reference		operator[](const difference_type &n) const	{ return *(*this + n); }
	};

	///////////// INTERMEDIATE /////////////

	template < typename T >
	reverse_iterator<T>		operator+(const typename reverse_iterator<T>::difference_type &n, const reverse_iterator<T> &s)
		{ return reverse_iterator<T>(s.base() - n); }

	template < typename T >
	reverse_iterator<T>		operator-(const typename reverse_iterator<T>::difference_type &n, const reverse_iterator<T> &s)
		{ return reverse_iterator<T>(s.base() + n); }

	template < typename TL, typename TR>
	typename reverse_iterator<TL>::difference_type
		operator+(const reverse_iterator<TL> &l, const reverse_iterator<TR> &r)
		{ return r.base() + l.base(); }

	template < typename TL, typename TR>
	typename reverse_iterator<TL>::difference_type
		operator-(const reverse_iterator<TL> &l, const reverse_iterator<TR> &r)
		{ return r.base() - l.base(); }

	////////////// CONDITIONS //////////////

	template < typename TL, typename TR >
	bool			operator==(const reverse_iterator<TL> &l, const reverse_iterator<TR> &r)
		{ return r.base() == l.base(); }

	template < typename TL, typename TR >
	bool			operator!=(const reverse_iterator<TL> &l, const reverse_iterator<TR> &r)
		{ return r.base() != l.base(); }

	template < typename TL, typename TR >
	bool			operator>=(const reverse_iterator<TL> &l, const reverse_iterator<TR> &r)
		{ return r.base() >= l.base(); }

	template < typename TL, typename TR >
	bool			operator<=(const reverse_iterator<TL> &l, const reverse_iterator<TR> &r)
		{ return r.base() <= l.base(); }

	template < typename TL, typename TR >
	bool			operator>(const reverse_iterator<TL> &l, const reverse_iterator<TR> &r)
		{ return r.base() > l.base(); }

	template < typename TL, typename TR >
	bool			operator<(const reverse_iterator<TL> &l, const reverse_iterator<TR> &r)
		{ return r.base() < l.base(); }

	//////////// RAW CONDITIONS ////////////

	template < typename T >
	bool			operator==(const reverse_iterator<T> &l, const typename reverse_iterator<T>::pointer &r)
		{ return r == l.base(); }

	template < typename T >
	bool			operator!=(const reverse_iterator<T> &l, const typename reverse_iterator<T>::pointer &r)
		{ return r != l.base(); }

	template < typename T >
	bool			operator>=(const reverse_iterator<T> &l, const typename reverse_iterator<T>::pointer &r)
		{ return r >= l.base(); }

	template < typename T >
	bool			operator<=(const reverse_iterator<T> &l, const typename reverse_iterator<T>::pointer &r)
		{ return r <= l.base(); }

	template < typename T >
	bool			operator>(const reverse_iterator<T> &l, const typename reverse_iterator<T>::pointer &r)
		{ return r > l.base(); }

	template < typename T >
	bool			operator<(const reverse_iterator<T> &l, const typename reverse_iterator<T>::pointer &r)
		{ return r < l.base(); }

	template < typename T >
	bool			operator==(const typename reverse_iterator<T>::pointer &r, const reverse_iterator<T> &l)
		{ return r == l.base(); }

	template < typename T >
	bool			operator!=(const typename reverse_iterator<T>::pointer &r, const reverse_iterator<T> &l)
		{ return r != l.base(); }

	template < typename T >
	bool			operator>=(const typename reverse_iterator<T>::pointer &r, const reverse_iterator<T> &l)
		{ return r >= l.base(); }

	template < typename T >
	bool			operator<=(const typename reverse_iterator<T>::pointer &r, const reverse_iterator<T> &l)
		{ return r <= l.base(); }

	template < typename T >
	bool			operator>(const typename reverse_iterator<T>::pointer &r, const reverse_iterator<T> &l)
		{ return r > l.base(); }

	template < typename T >
	bool			operator<(const typename reverse_iterator<T>::pointer &r, const reverse_iterator<T> &l)
		{ return r < l.base(); }

}

#endif /* __ITERATORS_HPP__ */