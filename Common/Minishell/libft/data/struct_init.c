/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:49:17 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/22 10:34:49 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_color	ft_color_new(int a, int r, int g, int b)
{
	t_color		color;

	color.a = (t_byte) a;
	color.r = (t_byte) r;
	color.g = (t_byte) g;
	color.b = (t_byte) b;
	return (color);
}

t_vector3	ft_vector3_new(int x, int y, int z)
{
	t_vector3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_vector2	ft_vector2_new(int x, int y)
{
	t_vector2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
