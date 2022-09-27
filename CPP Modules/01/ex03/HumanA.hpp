/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:45:32 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 00:43:07 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "header.hpp"

class HumanA
{
	private:
		Weapon			&weapon;
		std::string		name;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	attack(void);
};

#endif