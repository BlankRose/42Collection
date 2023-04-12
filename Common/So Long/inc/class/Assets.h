/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:25:05 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/23 19:14:35 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# include <mlx.h>
# include "more_types.h"
# include "settings.h"

typedef struct s_Image	t_img;
typedef struct s_Assets	t_pack;

t_pack	*new_pack(void *mlx);
t_pack	*del_pack(t_pack *this);

/**
 * Assets Class, handling all of the used images
 * */
struct s_Assets
{
	t_img	*exit;
	t_img	*item;
	t_img	*wall;
	t_img	*player;
	t_img	*rain[3];

	t_img	*(*get_asset)(t_pack *, char, int);
};

/**
 * Image SubClass, storing data about a singular image
 * */
struct s_Image
{
	void		*mlx;
	void		*data;
	t_string	path;
	t_int32		length;
	t_int32		height;
};

#endif /* ASSETS_H */