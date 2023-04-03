/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:43:05 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/21 19:21:26 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//
// CONSTRUCTORS
// All of Fixed class constructors
// Including: Default / From Int & Float Value / Copy
//

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int value)
{
	this->value = value << this->point;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(float value)
{
	this->value = roundf(value * (2 << (this->point - 1)));
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &f)
{
	this->value = f.value;
	std::cout << "Clone constructor called\n";
}

//
// DESTRUCTORS
// Called when destroyed
//

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

//
// OPERATORS
// Overloads operators to allows easier controls
// Includes: Assignement / Output
//

Fixed	&Fixed::operator=(const Fixed &f)
{
	this->value = f.value;
	std::cout << "Clone assigment operator called\n";
	return (*this);
}

std::ostream & operator << (std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}

//
// FUNCTIONS
//

int		Fixed::getPrecision(void) const
{
	int	precision = 0x0;
	for (int i = 0; i < this->point; i++)
		precision |= (this->value & 1 << i);
	
	return (precision);
}

int		Fixed::getMaxPrecision(void) const
{
	int precision = 0x0;
	for (int i = 0; i < this->point; i++)
		precision |= (1 << i);
	
	return (precision);
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

int		Fixed::toInt(void) const
{
	return (this->value >> this->point);
}

float	Fixed::toFloat(void) const
{
	float	res = this->value >> this->point;
	float	remaining = this->getPrecision();
	float	maxPrec = this->getMaxPrecision();

	if (!remaining || !maxPrec) return (res);
	return (res + (remaining / maxPrec));
}