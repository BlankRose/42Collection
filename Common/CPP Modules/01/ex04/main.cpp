/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:02:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/26 19:14:31 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int		main(int c, char **args)
{
	// Verify if there's 3 arguments
	if (c != 4) {
		std::cout << "\033[31mSyntax:\033[2m /replace <filename> <dest> <src>\n\033[0m";
		return (1);
	}

	// Open the File with IN and OUT
	std::string		filename = args[1], dest = args[2], src = args[3], file;
	std::ifstream	in(filename, std::fstream::in | std::fstream::out);
	std::ofstream	out(filename + ".replace", std::ofstream::trunc);
	if (!in.is_open() || !out.is_open()) {
		std::cout << "\033[31mFile:\033[2m Couldn't load files!\n\033[0m";
		return (1);
	}

	// Replace all occurences of DEST with SRC
	while (std::getline(in, file)) {
		size_t		j, slength(dest.length());

		for (size_t i = 0; i < file.length(); i++)
		{
			j = 0;
			while (file[i + j] == dest[j] && j < slength)
				j++;
			if (j == slength)
			{
				out << src;
				i += (j - 1);
			}
			else
				out << file[i];
		}
		out << "\n";
	}
	
	// Finally close the File
	in.close(); out.close();
	return (0);
}