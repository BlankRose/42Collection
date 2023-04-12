/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:37:10 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/24 10:58:07 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Assets.h"
#include <stdlib.h>

/**
 * SubClass Constructor
 * */
static t_img	*new_image(void *mlx, t_string path)
{
	t_img	*this;

	if (!mlx || !path)
		return (NULL);
	this = malloc(sizeof(t_img));
	if (!this)
		return (NULL);
	this->data = mlx_png_file_to_image(mlx, path,
			&this->length, &this->height);
	this->mlx = mlx;
	if (this->data)
		return (this);
	free(this);
	return (NULL);
}

/**
 * SubClass Destructor
 * */
static t_img	*del_image(t_img *this)
{
	if (!this)
		return (NULL);
	if (this->data)
		mlx_destroy_image(this->mlx, this->data);
	free(this);
	return (NULL);
}

/**
 * Gets the asset depending on the given TILE.
 * Returns NULL if not found or if not loaded properly!
 * */
t_img	*get_asset(t_pack *this, char tile, int frame)
{
	if (tile == TILE_SET[0])
		return (this->wall);
	if (tile == TILE_SET[2] || tile == TILE_ALT)
		return (this->player);
	if (tile == TILE_SET[3])
		return (this->exit);
	if (tile == TILE_SET[4])
		return (this->item);
	if (tile == TILE_SET[5])
		return (this->rain[frame]);
	return (NULL);
}

/**
 * Default Constructor
 * */
t_pack	*new_pack(void *mlx)
{
	t_pack	*this;

	if (!mlx)
		return (NULL);
	this = malloc(sizeof(t_pack));
	if (!this)
		return (NULL);
	this->get_asset = get_asset;
	this->exit = new_image(mlx, "assets/images/exit.png");
	this->wall = new_image(mlx, "assets/images/wall.png");
	this->item = new_image(mlx, "assets/images/item.png");
	this->player = new_image(mlx, "assets/images/player.png");
	this->rain[0] = new_image(mlx, "assets/images/rain_0.png");
	this->rain[1] = new_image(mlx, "assets/images/rain_1.png");
	this->rain[2] = new_image(mlx, "assets/images/rain_2.png");
	if (!this->exit || !this->wall || !this->item || !this->player
		|| !this->rain[0] || !this->rain[1] || !this->rain[2])
		return (del_pack(this));
	return (this);
}

/**
 * Destructor
 * */
t_pack	*del_pack(t_pack *this)
{
	if (!this)
		return (NULL);
	if (this->exit)
		del_image(this->exit);
	if (this->item)
		del_image(this->item);
	if (this->player)
		del_image(this->player);
	if (this->wall)
		del_image(this->wall);
	if (this->rain[0])
		del_image(this->rain[0]);
	if (this->rain[1])
		del_image(this->rain[1]);
	if (this->rain[2])
		del_image(this->rain[2]);
	free(this);
	return (NULL);
}
