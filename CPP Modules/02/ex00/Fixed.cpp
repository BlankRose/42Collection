/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:43:05 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/21 02:11:53 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &f)
{
	this->value = f.value;
	std::cout << "Clone constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &f)
{
	this->value = f.value;
	std::cout << "Clone assigment operator called\n";
	return (*this);
}

int		Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

void	Fixed::setRawBits(int value)
{
	std::cout << "setRawBits member function called\n";
	this->value = value;
}