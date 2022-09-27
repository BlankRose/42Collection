/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:26:02 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/19 18:51:10 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	Zombie::name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has been destroyed.\n";
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiinnnzzzZ...\n";
}

void	Zombie::setname(std::string name)
{
	Zombie::name = name;
}