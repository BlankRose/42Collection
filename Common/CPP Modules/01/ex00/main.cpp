/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:24:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/19 14:43:01 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int		main(void)
{
	Zombie	*zomb;

	zomb = newZombie("Ali");
	zomb->announce();
	randomChump("Undead Marie");
	delete zomb;
}