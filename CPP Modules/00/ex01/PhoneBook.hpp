/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:59:51 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/18 19:14:09 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "header.hpp"

class	PhoneBook
{
	private:
		Contact		**book;
	
	public:
		PhoneBook();
		~PhoneBook();
		void addcontact(void);
		void searchcontact(void);
};

#endif