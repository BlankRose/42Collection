/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3_Alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:53:11 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/22 15:40:03 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector3.h"
#include <stdlib.h>

t_vec3	*assign(t_vec3 *a, t_vec3 *b);
t_vec3	*multiply(t_vec3 *a, t_int64 b);
t_vec3	*divide(t_vec3 *a, t_int64 b);

/**
 * Allocates the right amount of memory for
 * the base of the Vector3 Class and assigns
 * member functions accordingly
 * 
 * @warning		May returns NULL if malloc failed!
 * */
static t_vec3	*new_vector3_base(void)
{
	t_vec3	*this;

	this = malloc(sizeof(t_vec3));
	if (!this)
		return (NULL);
	this->assign = assign;
	this->multiply = multiply;
	this->divide = divide;
	return (this);
}

/**
 * Default Constructor
 * */
t_vec3	*new_vector3(void)
{
	t_vec3	*this;

	this = new_vector3_base();
	if (!this)
		return (NULL);
	this->x = 0;
	this->y = 0;
	this->z = 0;
	return (this);
}

/**
 * Copy Constructor
 * */
t_vec3	*new_vector3_copy(t_vec3 *src)
{
	t_vec3	*this;

	this = new_vector3_base();
	if (!this)
		return (NULL);
	assign(this, src);
	return (this);
}

/**
 * Pre-Determined Values Constructor
 * */
t_vec3	*new_vector3_param(t_int64 x, t_int64 y, t_int64 z)
{
	t_vec3	*this;

	this = new_vector3_base();
	if (!this)
		return (NULL);
	this->x = x;
	this->y = y;
	this->z = z;
	return (this);
}

/**
 * Destructor
 * */
t_vec3	*del_vector3(t_vec3 *this)
{
	if (this)
		free(this);
	return (NULL);
}
