/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 23:56:17 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Span.hpp"
#include <random>

#define RANGE 10

int		main(void)
{
	Span	n(RANGE);
	srand(time(NULL));

	/* Fill span with random values */
	for (int i = 0; i < RANGE; i++) {
		int value = rand() % (RANGE * 100);
		n.addNumber(value);
		std::cout << value << " ; ";
	}
	std::cout << std::endl;

	/* Get shortest and longest spans */
	std::cout << "Shortest Span: " << n.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << n.longestSpan() << std::endl;

	/* Try to add more numbers */
	try {
		n.addNumber(1);
	} catch (std::exception &err) {
		std::cout << err.what() << std::endl;
	}

	/* Try to use addNumIter on smaller span */
	// Span				s(RANGE / 2);
	// std::vector<int>	v;

	// v.push_back(30);
	// v.push_back(12);
	// v.push_back(48);
	// v.push_back(458);
	// v.push_back(967);

	// try {
	// 	s.addNumberIterator(v.begin(), v.end());

	// 	/* Printing S values */
	// 	std::vector<int>	y = s.getValues();
	// 	for (int i = 0; i < RANGE / 2; i++) {
	// 		std::cout << "[" << i << "] ";
	// 		std::cout << y[i] << std::endl;
	// 	}
	// } catch (std::exception &err) {
	// 	std::cout << err.what() << std::endl;
	// }
}