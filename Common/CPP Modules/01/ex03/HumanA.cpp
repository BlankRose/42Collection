/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:47:33 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 00:53:31 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

// Constructor
HumanA::HumanA(std::string name, Weapon &weapon):
	weapon(weapon), name(name) {}

// Destructor
HumanA::~HumanA() {}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}