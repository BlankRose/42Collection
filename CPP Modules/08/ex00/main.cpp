/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 21:46:57 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "easyfind.hpp"
#include <vector>
# define RANGE 50

int		main(void)
{
	std::vector<int>	s(RANGE / 2);
	srand(time(NULL));

	for (size_t i = 0; i < s.size(); i++)
		s[i] = rand() % RANGE;

	for (size_t i = 0; i < 3; i++) {
		int goal = rand() % RANGE;
		std::cout << "Locating " << goal << ":" << std::endl;

		try {
			std::vector<int>::iterator	it = easyfind(s, goal);
			std::cout << *it << std::endl;
		} catch (std::exception &err) {
			std::cout << err.what() << std::endl;
		}
	}
}