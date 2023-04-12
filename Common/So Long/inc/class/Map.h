/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:14:11 by flcollar          #+#    #+#             */
/*   Updated: 2023/04/12 13:58:31 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "more_types.h"
# include "Vector3.h"
# include "libft.h"

typedef struct s_Map	t_map;

t_map	*new_map(void);
t_map	*del_map(t_map *this);

/**
 * Map Class, which stores mapping related data
 * */
struct s_Map
{
	t_list		*data;

	t_string	name;
	t_uint64	length;
	t_uint64	height;

	t_int64		items;
	t_int64		entry;
	t_int64		exit;

	t_uint64	moves;
	t_vec3		*player;
	t_int32		frame;
	t_vector2	verify;

	void		(*unload_map)(t_map *);
	t_list		*(*load_map)(t_map *, t_string);
};

#endif /* MAP_H */