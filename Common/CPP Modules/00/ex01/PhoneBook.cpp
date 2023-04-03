/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:18:32 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/23 17:18:59 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

PhoneBook::PhoneBook()
{
	book = (Contact **) calloc(MAX_CONTACT, sizeof(Contact *));

	for (int i = 0; i < MAX_CONTACT; i++)
		book[i] = 0;
}

PhoneBook::~PhoneBook()
{
	for (int i = 0; i < MAX_CONTACT; i++)
		if (book[i]) delete book[i];
	free(book);
}

void	PhoneBook::addcontact(void)
{
	/* Ask questions about the new contact */
	std::string		first, last, nick, phone, secret;

	while (first.empty()) {
		std::cout << "First Name: ";
		std::getline(std::cin, first);
	}

	while (last.empty()) {
		std::cout << "Last Name: ";
		std::getline(std::cin, last);
	}

	while (nick.empty()) {
		std::cout << "Nickname: ";
		std::getline(std::cin, nick);
	}

	while (phone.empty()) {
		std::cout << "Phone: ";
		std::getline(std::cin, phone);
	}

	while (secret.empty()) {
		std::cout << "Secret: ";
		std::getline(std::cin, secret);
	}

	/* Sets the new contact and remove the oldest when
	there's more than MAX_CONTACT */
	bool	placed = 0;
	for (int i = 0; i < MAX_CONTACT; i++){
		
		if (book[i]) {
			book[i]->modify_id(book[i]->fetch_id() + 1);
			if (book[i]->fetch_id() >= MAX_CONTACT) {
				delete book[i];
				book[i] = 0;
			}
		}

		if (!book[i] && !placed) {
			book[i] = new Contact(first, last, nick, phone, secret);
			placed = 1;
		}
	}
}

static char	*ftp_restrict_str(std::string target)
{
	const char 	*str = target.data();
	char		*res = (char *) calloc(11, sizeof(char));

	for (int i = 0; i < 10; i++) {
		res[i] = str[i];
		if (i == 9 && str[i + 1])
			res[i] = '.';
	}
	return (res);
}

void	PhoneBook::searchcontact(void)
{
	int		j = 1;

	/* Prints all registered contacts */
	std::cout << "\n   Index   │ First Name │ Last Name  │  Nickname ";
	std::cout << "\n═══════════╪════════════╪════════════╪═══════════";

	char	*target;
	for (int i = 0; i < MAX_CONTACT; i++) {
		
		if (book[i]) {
			target = ft_itoa(j);
			std::cout << "\n " << target; for (int y = 9 - strlen(target); y; y--) std::cout << " ";
			free(target);
			for (int y = ENTRY_NAME; y <= ENTRY_NICK; y++) {
				target = ftp_restrict_str(book[i]->fetch_entry(y));
				std::cout << " │ " << target; for (int z = 10 - strlen(target); z; z--) std::cout << " ";
				free(target);
			}
			j++;
		}
	}

	/* Return if no entries */
	if (j == 1) {
		std::cout << "\n    N/a    │\t  No entries avaibles yet! \n\n";
		return ;
	}

	/* Selection of Index and display all informations */
	std::string index;
	std::cout << "\n\nSelect Index: ";
	std::getline(std::cin, index);

	int		y = atoi(index.data()) + 1, x = 1;
	if (y <= j && y >= 2) {
		for (int i = 0; i < MAX_CONTACT; i++) {

			if (book[i]) x++;

			if (x == y) {
				for (int z = ENTRY_NAME; z <= ENTRY_SECRT; z++) {
					std::cout << "\n" << book[i]->fetch_entry(z);
				}
				break ;
			}
		}
	}

	else {
		std::cout << "Invalid index!";
	}

	std::cout << "\n\n";
}