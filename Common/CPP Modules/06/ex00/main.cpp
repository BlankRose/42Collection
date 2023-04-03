/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   CPP Modules - main.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Fri Jun  3 17:34:44 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include <iostream>
#include <exception>
#include <string>
#include <limits>

static bool		hasDot(double value)
{
	// Checks wether it contains precision or not
	if (value - static_cast<int> (value)) return false;
	else return true;
}

static void		display(double value)
{
	// Display char equivalent
	std::cout << "char: ";
	if (hasDot(value) && value >= -__SCHAR_MAX__ - 1 && value <= __INT_MAX__) {
		if (value < 32 || value > 126) std::cout << "Non displayable";
		else std::cout << "\'" << static_cast<char> (value) << "\'";
	}
	else std::cout << "Impossible";
	std::cout << std::endl;

	// Display int equivalent
	std::cout << "int: ";
	if (hasDot(value) && value >= -__INT_MAX__ - 1 && value <= __INT_MAX__)
		std::cout << static_cast<int> (value);
	else std::cout << "Impossible";
	std::cout << std::endl;

	// Display float equivalent
	float	fvalue = static_cast<float> (value);
	std::cout << "float: " << fvalue;
	if (hasDot(value) && value < 1e6 && value > -1e6)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	// Display double equivalent
	std::cout << "double: " << value;
	if (hasDot(value) && value < 1e6 && value > -1e6)
		std::cout << ".0";
	std::cout << std::endl;
}

int		main(int c, char **args)
{
	// Checks if any argument is given
	if (c < 2) {
		std::cout << "\033[31;1mSYNTAX: \033[0;31;2m./convert <value>\033[0m" << std::endl;
		return 1;
	}

	// Loops through every Arguments
	for (int i = 1; args[i]; i++) {
		std::string		arg(args[i]);
		double			value;

		// Grab the value of arguments converted into Double
		try { value = std::stod(arg); }
		catch (std::invalid_argument &err) {
			value = std::stod("nan");
		}
		catch (std::out_of_range &err) {
			if (arg[0] == '-') value = std::stod("-inf");
			else value = std::stod("inf");
		}

		// New line to seperate each convertions then display
		if (i > 1) std::cout << std::endl;
		std::cout << "\033[1;4mEquivalents for [" << arg << "] :\033[0m" << std::endl;
		display(value);
	}
}