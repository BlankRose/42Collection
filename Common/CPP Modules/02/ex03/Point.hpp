/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:59:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/28 23:47:38 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const		*x;
		Fixed const		*y;
	
	public:
		Point();
		Point(const int&, const int&);
		Point(const float&, const float&);
		Point(const Point&);
		~Point();

		Point		&operator=(const Point&);
		bool		operator==(const Point&) const;

		const Fixed		&getX() const;
		const Fixed		&getY() const;
};

#endif