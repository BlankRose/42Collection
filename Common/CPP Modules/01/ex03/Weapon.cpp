/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:35:50 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 00:18:50 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Weapon::Weapon(std::string type)
{
	Weapon::type = type;
}

Weapon::~Weapon()
{
}

std::string		&Weapon::getType(void)
{
	return (type);
}

void			Weapon::setType(std::string type)
{
	Weapon::type = type;
}