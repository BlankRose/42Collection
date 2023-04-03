/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 20:00:04 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "iter.hpp"
#include <random>

void	capitalize(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}

void	addTwo(int &i)
{
	i += 2;
}

int		main(void)
{
	/* INTS */
	int		*tab = new int[10];

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		tab[i] = rand() % 300;
		std::cout << tab[i] << " ; ";
	}

	std::cout << std::endl;
	iter(tab, 10, addTwo);

	for (int i = 0; i < 10; i++) {
		std::cout << tab[i] << " ; ";
	}

	std::cout << std::endl;

	/* STRINGS */
	std::string		str = "I like turtles_yey!";
	std::cout << str << std::endl;
	iter(const_cast<char *> (str.data()), str.length(), capitalize);
	std::cout << str << std::endl;
}