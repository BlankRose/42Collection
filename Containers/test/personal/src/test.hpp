/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   FT_Containers - test.hpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Mon Nov 14 12:34:34 CET 2022      */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __TEST_HPP__
# define __TEST_HPP__

///// SWITCH FOR INDIVIDUAL FEATURES /////

// Reverse iterator testing
// (used in display of values)
// # define REVERSE_ITER

// Enables vector testing
# define CHECK_VECTOR

// Enable map testing
# define CHECK_MAP

// Enables stack testing
# define CHECK_STACK



///// NEEDED INCLUDES FOR TESTING /////

# include <ctime>
# include <chrono>
# include <iostream>

# include <vector>
# include "../../../src/vector.hpp"

# include <map>
# include "../../../src/map.hpp"

# include <stack>
# include "../../../src/stack.hpp"



///// QUICK DEFINES FOR PRINTING /////

template < class T >
void	print_value(const T value)
	{ std::cout << value << std::endl; }

template < class T >
void	print_pair(const T values)
	{ std::cout << values.first << " = " << values.second << std::endl; }

template < class T >
void	print_content(T &c)
{
# ifdef REVERSE_ITER
	for (typename T::reverse_iterator i = c.rbegin(); i != c.rend(); i++)
#else
	for (typename T::iterator i = c.begin(); i != c.end(); i++)
#endif
		std::cout << *i << " ; ";
	std::cout << std::endl;
}

template < class T >
void	print_dual(T &c)
{
# ifdef REVERSE_ITER
	for (typename T::reverse_iterator i = c.rbegin(); i != c.rend(); i++)
#else
	for (typename T::iterator i = c.begin(); i != c.end(); i++)
#endif
		std::cout << (*i).first << " = " << (*i).second << " ; ";
	std::cout << std::endl;
}



///// TIMESTAMP GENERATOR /////

class Chrono
{
	public:
		typedef long long		time_type;

	private:
		time_type		_begin;

	public:
		Chrono(): _begin(setTime()) {}
		Chrono(const time_type &n): _begin(n) {}
		Chrono(const Chrono &s): _begin(s._begin) {}
		~Chrono() {}

		Chrono				&operator=(const Chrono &s)
			{ _begin = s._begin; return *this; }

		static time_type	epoch(void)
			{ return std::chrono::system_clock::now().time_since_epoch().count(); }
		time_type			setTime(const time_type &n = epoch())
			{ _begin = n; return _begin; }

		time_type			begin(void) const { return _begin; }
		time_type			elapsed(void) const { return epoch() - _begin; }
};

std::ostream		&operator<<(std::ostream &o, const Chrono &t);



////// QUICK DEFINITIONS FOR READIBILITY /////

#define NEW_ENTRY(color, text) std::cout << std::endl << "\033[" << color << ";4;1m" << text << "\033[0m" << std::endl;
#define NEW_TITLE(color, text) std::cout << std::endl << "\033[" << color << ";4;3;1m===  " << text << "  ===\033[0m" << std::endl;

#define CASUAL(text) std::cout << "\033[2m" << text << "\033[0m" << std::endl;

#define PRINT(text, container) std::cout << "\033[2m" << text << " = \033[0m"; print_content(container);
#define PRINT2(text, container) std::cout << "\033[2m" << text << " = \033[0m"; print_dual(container);
#define PRINTTIME(color, a, b) std::cout << "\033[" << color << ";3mPerformances:\033[0;2m\tSTD = " << a << "ms | FT = " << b << "ms\033[0m" << std::endl;

#define SHOW(text, value) std::cout << "\033[2m" << text << " = \033[0m"; print_value(value);
#define SHOW2(text, value) std::cout << "\033[2m" << text << " = \033[0m"; print_pair(value);

#define TIME_START(store) store.setTime();
#define TIME_ADD(store, begin) store += begin.elapsed();
#define TIME_FINISH(store, begin) store = begin.elapsed();



///// CONTAINERS TESTERS FUNCTIONS /////

void	test_vector(void);
void	test_map(void);
void	test_stack(void);

#endif /* __TEST_HPP__ */