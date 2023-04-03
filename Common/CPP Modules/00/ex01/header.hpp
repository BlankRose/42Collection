/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:41:34 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/18 20:20:55 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "Contact.hpp"
#include "PhoneBook.hpp"

#define MAX_CONTACT 8
#define ENTRY_NAME 1
#define ENTRY_LAST 2
#define ENTRY_NICK 3
#define ENTRY_PHONE 4
#define ENTRY_SECRT 5

char	*ft_itoa(int n);

#endif