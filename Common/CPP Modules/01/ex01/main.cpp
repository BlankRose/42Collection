/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:24:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/19 19:09:37 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie	*zombieHorde(int n, std::string name);

int		main(void)
{
	int			count = 8;
	Zombie		*horde = zombieHorde(count, "Jamie");

	for (int i = 0; i < count; i++)
		horde[i].announce();
	
	free(horde);
}