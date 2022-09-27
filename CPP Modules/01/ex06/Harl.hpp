/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:29:25 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/26 19:06:21 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <map>
#include <string>
#include <iostream>

class Harl;

typedef struct s_list {
	struct s_list		*next;
	std::string			index;
	void (Harl::*ft)(void);
} t_list;

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		t_list			*lst;
		std::string		level;

	public:
		Harl();
		~Harl();

		void	setLevel(std::string level);
		void	complain(std::string level);
};

#endif