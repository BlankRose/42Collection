/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:35:54 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 00:13:34 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "header.hpp"

class Weapon
{
	private:
		std::string		type;

	public:
		Weapon(std::string type);
		~Weapon();
		
		std::string		&getType(void);
		void			setType(std::string);
};

#endif