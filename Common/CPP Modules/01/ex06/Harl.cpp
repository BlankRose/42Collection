/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:31:55 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/26 19:07:40 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->lst = new t_list;
	this->lst->index = "debug";
	this->lst->ft = &Harl::debug;
	this->lst->next = new t_list;

	t_list	*lst = this->lst->next;
	lst->index = "info";
	lst->ft = &Harl::info;
	lst->next = new t_list;

	lst = lst->next;
	lst->index = "warning";
	lst->ft = &Harl::warning;
	lst->next = new t_list;

	lst = lst->next;
	lst->index = "error";
	lst->ft = &Harl::error;
	lst->next = 0;

	this->level = "debug";
}

Harl::~Harl()
{
	t_list	*current = this->lst, *next;

	while (current) {
		next = current->next;
		delete current;
		current = next;
	}
}

void	Harl::debug(void)
{
	std::cout << "\033[1;2mDEBUG:\033[0;2m The nuclear core has started.\n\033[0m";
}

void	Harl::info(void)
{
	std::cout << "\033[1mINFO:\033[0m The nuclear core is heating.\n";
}

void	Harl::warning(void)
{
	std::cout << "\033[33;1mWARNING:\033[0;33m The nuclear core is overheating!\n\033[0m";
}

void	Harl::error(void)
{
	std::cout << "\033[31;1mERROR:\033[0;31m The nuclear core has exploded!\n\033[0m";
}

void	Harl::setLevel(std::string level)
{
	t_list	*current = this->lst;
	this->level = level;

	while (current) {
		if (current->index == level)
			return ;
		current = current->next;
	}

	std::cout << "\033[1;2m* Beep *\n\033[0m";
}

void	Harl::complain(std::string level)
{
	t_list	*current = this->lst;
	bool	lock = true;

	while (current) {
		if (current->index == this->level)
			lock = false;
		if (current->index == level && !lock) {
			(this->*(current->ft))();
			return ;
		}
		current = current->next;
	}
}