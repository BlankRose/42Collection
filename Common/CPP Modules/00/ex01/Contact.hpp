/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:02:54 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/18 20:13:41 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "header.hpp"

class Contact
{
	private:
		std::string		first;
		std::string		last;
		std::string		nick;
		std::string		phone;
		std::string		hidden;
		int				id;

	public:
		Contact(std::string first_name, std::string last_name, std::string nickname,
			std::string number, std::string secret);
		~Contact();
		int				fetch_id(void);
		void			modify_id(int value);
		std::string		fetch_entry(int entry);
};

#endif