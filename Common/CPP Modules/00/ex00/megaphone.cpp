/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:19:46 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/18 15:38:19 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*ftp_uppercase(char *str)
{
	char	*tmp = str;

	while (*tmp) {
		if (*tmp >= 'a' && *tmp <= 'z')
			*tmp = *tmp - 'a' + 'A';
		tmp++;
	}
	return (str);
}

int		main(int c, char **args)
{
	if (c < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (c >= 2 && *(++args))
		std::cout << ftp_uppercase(*args);
	std::cout << "\n";
}