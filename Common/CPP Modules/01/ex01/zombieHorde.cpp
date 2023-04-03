/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:45:28 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/19 18:59:47 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*horde = (Zombie *) malloc(sizeof(Zombie) * n);

	for (int i = 0; i < n; i++)
		horde[i].setname(name);

	return (&horde[0]);
}