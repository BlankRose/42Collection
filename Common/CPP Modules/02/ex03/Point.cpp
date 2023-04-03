/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:55:35 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/28 23:48:41 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//
// CONSTRUCTORS
// All of Fixed class constructors
// Including: Default / From Int & Float Value / Copy
//

Point::Point()
{
	this->x = new Fixed();
	this->y = new Fixed();
}

Point::Point(const int &x, const int &y)
{
	this->x = new Fixed(x);
	this->y = new Fixed(y);
}

Point::Point(const float &x, const float &y)
{
	this->x = new Fixed(x);
	this->y = new Fixed(y);
}

Point::Point(const Point &p)
{
	this->x = new Fixed(*p.x);
	this->y = new Fixed(*p.y);
}

Point::~Point()
{
	delete this->x;
	delete this->y;
}

//
// OPERATORS
// Including: Affectation & Comparaison
//

Point	&Point::operator=(const Point &p)
{
	delete this->x;
	delete this->y;
	this->x = new Fixed(*p.x);
	this->y = new Fixed(*p.y);
	return *this;
}

bool	Point::operator==(const Point &p) const
{
	return (*this->x == *p.x && *this->y == *p.y);
}

//
// MEMBER FUNCTIONS
//

const Fixed	&Point::getX() const {return *this->x;}
const Fixed	&Point::getY() const {return *this->y;}
