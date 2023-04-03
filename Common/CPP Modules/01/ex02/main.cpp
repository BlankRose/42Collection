/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:02:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/19 23:29:50 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int		main(void)
{
	/* Assigning variables */
	std::string		str = "HI THIS IS BRAIN";
	std::string		*stringPTR = &str;
	std::string		&stringREF = str;

	/* Print memory address */
	std::cout << "Address of STR:\t\t" << &str << "\n";
	std::cout << "Address held by PTR:\t" << stringPTR << "\n";
	std::cout << "Address held by REF:\t" << &stringREF << "\n";

	/* Print values */
	std::cout << "Value of STR:\t\t" << str << "\n";
	std::cout << "Value held by PTR:\t" << *stringPTR << "\n";
	std::cout << "Value held by REF:\t" << stringREF << "\n";
}