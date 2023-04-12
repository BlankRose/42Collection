/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:52:57 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/23 10:49:27 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include "more_types.h"

typedef struct s_Vector3	t_vec3;

t_vec3	*new_vector3(void);
t_vec3	*new_vector3_copy(t_vec3 *src);
t_vec3	*new_vector3_param(t_int64 x, t_int64 y, t_int64 z);
t_vec3	*del_vector3(t_vec3 *this);

/**
 * Vector3 Class, which allows some easier calculus
 * */
struct s_Vector3
{
	t_int64		y;
	t_int64		x;
	t_int64		z;

	t_vec3		*(*assign)(t_vec3 *, t_vec3 *);
	t_vec3		*(*multiply)(t_vec3 *, t_int64);
	t_vec3		*(*divide)(t_vec3 *, t_int64);
};

#endif /* VECTOR3_H */