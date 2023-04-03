/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:40:35 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/19 13:57:19 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int		main(void)
{
	PhoneBook		book;
	std::string		cmd;

	while (true) {
		std::cout << "$> ";
		std::getline(std::cin, cmd);

		if (cmd == "EXIT")
			return (0);
		
		if (cmd == "ADD")
			book.addcontact();

		if (cmd == "SEARCH")
			book.searchcontact();
	}
}