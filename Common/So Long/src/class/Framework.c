/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Framework.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:10:21 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/23 17:35:44 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Framework.h"
#include <stdlib.h>

/**
 * Creates a new window, ready to use.
 * When giving NULL instead of a proper title, it will only
 * destroys the window inplace.
 * 
 * @warning		It will destroys old one if there's already one in place
 * @return		TRUE or FALSE upon SUCCESS or FAILURE
 * */
int	new_window(t_fw *this, t_int32 x, t_int32 y, t_string title)
{
	if (this->win)
		mlx_destroy_window(this->mlx, this->win);
	if (!title)
		return (SUCCESS);
	this->win = mlx_new_window(this->mlx, x, y, title);
	if (!this->win)
		return (FAILURE);
	this->win_length = x;
	this->win_height = y;
	return (SUCCESS);
}

/**
 * Place a new image on the window at given location,
 * while also fixing displacement bugs, caused by the MLX
 * */
void	put_tile(t_fw *this, t_img *img, t_int32 x, t_int32 y)
{
	t_uint8		offset_x;
	t_uint8		offset_y;

	if (!this || !this->win || !img)
		return ;
	offset_x = 0;
	if (x * TILE_SIZE > this->win_length / 2)
		offset_x = 1;
	offset_y = 0;
	if (y * TILE_SIZE > this->win_height / 2)
		offset_y = 1;
	mlx_put_image_to_window(this->mlx, this->win, img->data,
		TILE_SIZE * x - offset_x, TILE_SIZE * y - offset_y);
}

/**
 * Clears a tile at given location
 * */
void	clear_tile(t_fw *this)
{
	if (!this || !this->win)
		return ;
	mlx_clear_window(this->mlx, this->win);
}

/**
 * Default Constructor
 * */
t_fw	*new_framework(void)
{
	t_fw	*this;

	this = malloc(sizeof(t_fw));
	if (!this)
		return (NULL);
	this->mlx = mlx_init();
	if (!this->mlx)
		return (del_framework(this));
	this->new_window = new_window;
	this->put_tile = put_tile;
	this->clear_tile = clear_tile;
	this->win_height = 0;
	this->win_length = 0;
	this->win = NULL;
	return (this);
}

/**
 * Destructor
 * */
t_fw	*del_framework(t_fw *this)
{
	if (!this)
		return (NULL);
	if (this->win)
		mlx_destroy_window(this->mlx, this->win);
	if (this->mlx)
		free(this->mlx);
	free(this);
	return (NULL);
}
