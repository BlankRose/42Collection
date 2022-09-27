/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:35:23 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/29 08:00:11 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static float getArea(Point const a, Point const b, Point const c)
{
	float area =
		( a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
		+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
		+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())
		) / 2.0;
	if (area < 0)
		return -area;
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (point == a || point == b || point == c) return false;

	float	cmp = getArea(a, b, c);
	float	area_a = getArea(point, b, c);
	float	area_b = getArea(a, point, c);
	float	area_c = getArea(a, b, point);

	if (!area_a || !area_b || !area_c) return false;
	return (cmp == area_a + area_b + area_c);
}