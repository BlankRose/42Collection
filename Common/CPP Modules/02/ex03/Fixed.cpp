/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:43:05 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/28 22:20:37 by flcollar         ###   ########.fr       */
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
}

Fixed::Fixed(int value)
{
	this->value = value << this->point;
}

Fixed::Fixed(float value)
{
	this->value = roundf(value * (2 << (this->point - 1)));
}

Fixed::Fixed(const Fixed &f)
{
	this->value = f.value;
}

//
// DESTRUCTORS
// Called when destroyed
//

Fixed::~Fixed() {}

//
// OPERATORS
// Overloads operators to allows easier controls
// Includes: Assignement / Output
//

Fixed	&Fixed::operator=(const Fixed &f)
{
	this->value = f.value;
	return (*this);
}

std::ostream & operator << (std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}

Fixed	operator+(const Fixed &a, const Fixed &b) {return (Fixed(a.toFloat() + b.toFloat()));}
Fixed	operator-(const Fixed &a, const Fixed &b) {return (Fixed(a.toFloat() - b.toFloat()));}
Fixed	operator*(const Fixed &a, const Fixed &b) {return (Fixed(a.toFloat() * b.toFloat()));}
Fixed	operator/(const Fixed &a, const Fixed &b) {return (Fixed(a.toFloat() / b.toFloat()));}

bool	Fixed::operator==(const Fixed&f) const {return this->toFloat() == f.toFloat();}
bool	Fixed::operator!=(const Fixed&f) const {return this->toFloat() != f.toFloat();}
bool	Fixed::operator>=(const Fixed&f) const {return this->toFloat() >= f.toFloat();}
bool	Fixed::operator<=(const Fixed&f) const {return this->toFloat() <= f.toFloat();}
bool	Fixed::operator>(const Fixed&f) const {return this->toFloat() > f.toFloat();}
bool	Fixed::operator<(const Fixed&f) const {return this->toFloat() < f.toFloat();}

Fixed	&Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++*this;
	return tmp;
}

Fixed	&Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--*this;
	return tmp;
}

//
// FUNCTIONS
// Every member functions of the Class
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