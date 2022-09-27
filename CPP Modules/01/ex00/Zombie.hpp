/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:01:58 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/19 14:38:37 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string		name;

	public:
		Zombie(std::string name);
		~Zombie();

		void	announce(void);
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif