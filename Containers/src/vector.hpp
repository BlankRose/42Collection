/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - vector.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Tue Feb  7 15:17:05 CET 2023      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#include "tools.hpp"
namespace ft {

	template < class Type, class Allocator = std::allocator<Type> >
	class vector
	{
		public:
			/////////////// TYPEDEF ////////////////

			typedef Type											value_type;
			typedef Allocator										allocator_type;
			typedef ft::random_access_iterator<Type>				iterator;
			typedef ft::random_access_iterator<const Type>			const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename Allocator::difference_type				difference_type;
			typedef typename Allocator::const_reference				const_reference;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef typename Allocator::reference					reference;
			typedef typename Allocator::size_type					size_type;
			typedef typename Allocator::pointer						pointer;

		protected:
			////////////// VARIABLES ///////////////

			pointer			_array;
			allocator_type	_alloc;
			size_type		_capacity;
			size_type		_size;

		private:
			/////////// PRIVATE METHODS ////////////

			template < class T >
			void		quick_swap(T &one, T &other) {
				T	tmp = one;
				one = other;
				other = tmp;
			}

			void		realloc(size_type n) {
				pointer		new_array = _alloc.allocate(n);
				size_type	i;
				for (i = 0; i < _size && i < n; i++)
					_alloc.construct(&new_array[i], _array[i]);

				if (_array) {
					this->clear();
					_alloc.deallocate(_array, _capacity);
				}

				this->_size = i;
				this->_array = new_array;
				this->_capacity = n;
			}

		public:
			///////////// CONSTRUCTORS /////////////

			explicit vector(const allocator_type &alloc = allocator_type()):
				_array(nullptr), _alloc(alloc), _capacity(0), _size(0) {};

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()):
				_alloc(alloc), _capacity(n), _size(n)
			{
				_array = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_array[i], val);
			};

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0):
				_alloc(alloc)
			{
				size_type	n = 0;
				for (InputIterator it = first; it != last; it++)
					n++;

				_capacity = n;
				_size = n;
				_array = _alloc.allocate(n);

				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_array[i], *(first++));
			};

			vector(const vector &src):
				_alloc(src._alloc), _capacity(src._capacity), _size(src._size)
			{
				_array = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], src._array[i]);
			};

			~vector()
			{
				this->clear();
				_alloc.deallocate(_array, _capacity);
			};

			////////////// OPERATORS ///////////////

			reference		operator[](size_type position) { return this->at(position); }
			const_reference	operator[](size_type position) const { return this->at(position); }

			vector<Type>	&operator=(const vector<Type> &src) {
				this->clear();
				this->reserve(src._size);

				for (size_type i = 0; i < src._size; i++)
					_alloc.construct(&this->_array[i], src._array[i]);
				this->_size = src._size;
				return *this;
			}

			/////////////// METHODS ////////////////

			// DATA ACCESSING

			Allocator				get_allocator(void) const { return _alloc; }

			iterator				begin(void)			{ return iterator(_array); }
			iterator				end(void)			{ return iterator(&_array[_size]); }
			reverse_iterator		rbegin(void)		{ return reverse_iterator(end()); }
			reverse_iterator		rend(void)			{ return reverse_iterator(begin()); }
			reference				front()				{ return _array[0]; }
			reference				back()				{ return _array[_size - 1]; }
			pointer					data(void)			{ return _array; }

			const_iterator			begin(void) const	{ return const_iterator(_array); }
			const_iterator			end(void) const		{ return const_iterator(&_array[_size]); }
			const_reverse_iterator	rbegin(void) const	{ return const_reverse_iterator(end()); }
			const_reverse_iterator	rend(void) const	{ return const_reverse_iterator(begin()); }
			const_reference			front() const		{ return _array[0]; }
			const_reference			back() const		{ return _array[_size - 1]; }
			const_pointer			data(void) const	{ return _array; }

			const_reference			at(size_type pos) const
			{
				if (pos >= _size) throw
					std::out_of_range("Out of vector's range!");
				return this->_array[pos];
			}
			reference				at(size_type pos)
			{
				if (pos >= _size) throw
					std::out_of_range("Out of vector's range!");
				return this->_array[pos];
			}

			// CAPACITY

			size_type		size(void) const { return this->_size; }
			size_type		capacity(void) const { return this->_capacity; }
			bool			empty(void) const { return this->_size == 0; }

			size_type		max_size(void) const
				{ return std::min((size_type) std::numeric_limits<difference_type>::max(), std::numeric_limits<size_type>::max() / sizeof(value_type)); }

			void			reserve(size_type n)
			{
				if (n >= this->max_size())
					throw std::length_error("Reserve argument goes beyond max size of vector!");
				if (n <= _capacity) return;
				this->realloc(n);
			}

			// MODIFIERS

			void			clear(void)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				_size = 0;
			}

			void			push_back(const Type &value)
			{
				if (_capacity == 0){
					_capacity = 1;
					_array = _alloc.allocate(_capacity);
					_alloc.construct(&_array[0], value);
					_size++;
					return;
				}
				if (_capacity > _size)
        	    {
        	        _alloc.construct(&_array[_size], value);
        	        _size++;
        	        return;
        	    }
				size_type	tmpCap = _capacity * 2;
				pointer tmp = _alloc.allocate(tmpCap);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(&tmp[i], _array[i]);
					_alloc.destroy(&_array[i]);
				}
				_alloc.deallocate(_array, _capacity);
				_capacity = tmpCap;
				_array = tmp;
				_alloc.construct(&_array[_size], value);
				_size++;
				return;
			}

			void			pop_back(void)
			{
				if (!_size) return;
				_alloc.destroy(&_array[--_size]);
			}

			void			resize(size_type count, Type value = Type())
			{
				this->realloc(count);
				for (size_type i = _size; i < count; i++) {
					_alloc.construct(&_array[i], value);
					_size++;
				}
			}

			void			swap(vector &other)
			{
				this->quick_swap(this->_array, other._array);
				this->quick_swap(this->_size, other._size);
				this->quick_swap(this->_alloc, other._alloc);
				this->quick_swap(this->_capacity, other._capacity);
			}

			iterator	insert(iterator pos, const Type &value)
			{
				difference_type		newPos = pos - this->begin();
				this->insert(pos, (size_type) 1, value);
				return (this->begin() + newPos);
			}

			void		insert(iterator pos, size_type count, const Type &value)
			{
				if (!count) return ;

				iterator		it = this->end();
				vector<Type>	tmp(pos, it++);
				if (count + _size > _capacity)
					reserve(count + _size);

				while (--it != pos)
					this->pop_back();
				for (; count; count--)
					this->push_back(value);
				for (it = tmp.begin(); it != tmp.end(); it++)
					this->push_back(*it);
			}

			template < class InputIt >
			void		insert(iterator pos, InputIt first, InputIt last,
				typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0)
			{
				if (first == last) return ;
				iterator		it = this->end();
				vector<Type>	tmp(pos, it++);
				vector<Type>	dup(first, last);
				iterator	fs = dup.begin(), ls = dup.end();

				if ((ls - fs) + _size > _capacity)
					reserve((ls - fs) + _size);
				while (--it != pos)
					this->pop_back();
				while (fs != ls)
					this->push_back(*(fs++));
				for (it = tmp.begin(); it != tmp.end(); it++)
					this->push_back(*it);
			}

			iterator	erase(iterator pos)
			{
				size_type		i = pos - this->begin();
				_alloc.destroy(&_array[i]);
				std::move(&_array[i + 1], &_array[_size--], &_array[i]);
				return pos;
			}

			iterator	erase(iterator first, iterator last)
			{
				size_type	n = last - first;
				size_type	i = first - this->begin();
				_alloc.destroy(&_array[i]);
				std::move(&_array[i + n], &_array[_size], &_array[i]);
				_size -= n;
				return first;
			}

			template < class InputIt >
			void		assign(InputIt begin, InputIt end) { *this = vector(begin, end); }
			void		assign(size_type n, const Type &value) { *this = vector(n, value); }
	
	};

	////////////// OPERATORS ///////////////

	template < class T, class Alloc >
	bool		operator==(const vector<T, Alloc> &l, const vector<T, Alloc> &r)
		{ return l.size() == r.size() && ft::equal(l.begin(), l.end(), r.begin()); }

	template < class T, class Alloc >
	bool		operator!=(const vector<T, Alloc> &l, const vector<T, Alloc> &r)
		{ return !(l == r); }

	template < class T, class Alloc >
	bool		operator<(const vector<T, Alloc> &l, const vector<T, Alloc> &r)
		{ return ft::lexicographical_compare(l.begin(), l.end(), r.begin(), r.end()); }

	template < class T, class Alloc >
	bool		operator>(const vector<T, Alloc> &l, const vector<T, Alloc> &r)
		{ return r < l; }

	template < class T, class Alloc >
	bool		operator>=(const vector<T, Alloc> &l, const vector<T, Alloc> &r)
		{ return !(l < r); }

	template < class T, class Alloc >
	bool		operator<=(const vector<T, Alloc> &l, const vector<T, Alloc> &r)
		{ return !(r < l); }

	template < class T, class Alloc >
	void		swap(const vector<T, Alloc> &l, const vector<T, Alloc> &r)
		{ l.swap(r); }

}

#endif