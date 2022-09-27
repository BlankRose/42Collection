/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Array.hpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 20:59:02 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <iostream>
#include <exception>

template <class T>
class Array
{
	private:
		//////////// VARIABLES /////////////

		size_t	len;
		T		*array;

	public:
		/////////// CONSTRUCTORS ///////////

		Array() {
			this->array = new T[1];
			this->array[0] = T();
			this->len = 1;
		};

		Array(unsigned int n) {
			this->array = new T[n];
			for (size_t i = 0; i < n; i++)
				this->array[i] = T();
			this->len = n;
		};

		Array(const Array &a) {
			this->array = new T[a.len];
			for (size_t i = 0; i < a.len; i++)
				this->array[i] = a.array[i];
			this->len = a.len;
		};

		~Array() {delete[] this->array;};

		//////////// OPERATORS /////////////

		Array		&operator=(const Array &a) {
			delete[] this->array;
			this->array = new T[a.len];
			for (size_t i = 0; i < a.len; i++)
				this->array[i] = a.array[i];
			this->len = a.len;
			return *this;
		};

		//////////// FUNCTIONS /////////////

		T			&operator[](const int &index) {
			if (index < 0 || index >= static_cast<int> (this->len))
				throw OutOfBound();
			return this->array[index];
		};

		//////////// EXCEPTIONS ////////////

		size_t		size(void) {return this->len;};

		class OutOfBound: public std::exception
		{
			public:
				virtual const char *what() const throw()
					{return "Index out of bound!";}
		};
};

#endif