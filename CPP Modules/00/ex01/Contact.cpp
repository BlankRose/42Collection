/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:08:28 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/18 20:13:32 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string number, std::string secret)
{
	first = first_name;
	last = last_name;
	nick = nickname;
	hidden = secret;
	phone = number;
	id = 0;
}

int				Contact::fetch_id(void)
{
	return (id);
}

std::string		Contact::fetch_entry(int entry)
{
	if (entry == 1)
		return (first);
	if (entry == 2)
		return (last);
	if (entry == 3)
		return (nick);
	if (entry == 4)
		return (phone);
	if (entry == 5)
		return (hidden);
	return ("Invalid!");
}

void			Contact::modify_id(int value)
{
	id = value;
}

Contact::~Contact()
{
}