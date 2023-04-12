/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3_Methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:53:16 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/22 13:20:30 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector3.h"

t_vec3	*assign(t_vec3 *this, t_vec3 *other)
{
	this->x = other->x;
	this->y = other->y;
	this->z = other->z;
	return (this);
}

t_vec3	*multiply(t_vec3 *this, t_int64 multiplier)
{
	this->x *= multiplier;
	this->y *= multiplier;
	this->z *= multiplier;
	return (this);
}

t_vec3	*divide(t_vec3 *this, t_int64 multiplier)
{
	this->x /= multiplier;
	this->y /= multiplier;
	this->z /= multiplier;
	return (this);
}
