/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:47:33 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 00:53:26 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

// Constructor
HumanB::HumanB(std::string name):
	weapon(NULL), name(name) {}

// Destructor
HumanB::~HumanB() {}

void	HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
	else
		std::cout << name << " attacks with their fists\n";
}

void	HumanB::setWeapon(Weapon &type)
{
	this->weapon = &type;
}