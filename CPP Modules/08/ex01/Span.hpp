/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - Span.hpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 23:52:55 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <limits>

class Span
{
	private:
		std::vector<int>	values;
		size_t				limit;

	public:
		Span();
		Span(const size_t&);
		Span(const Span&);
		~Span();

		Span		&operator=(const Span&);

		std::vector<int>	getValues(void);
		void				addNumber(int nb);
		void				addNumberIterator(std::vector<int>::iterator, std::vector<int>::iterator);
		int					shortestSpan(void);
		int					longestSpan(void);

		class MaxEntries: public std::exception
		{
			public:
				virtual const char *what() const throw()
					{return "The Span is full!";}
		};

		class LowEntries: public std::exception
		{
			public:
				virtual const char *what() const throw()
					{return "Needs atleast 2 entries to do that!";}
		};

		class NotEnoughSpace: public std::exception
		{
			public:
				virtual const char *what() const throw()
					{return "Not enough room to fit every values!";}
		};
};

#endif