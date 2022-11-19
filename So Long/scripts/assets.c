/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:18:25 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/25 18:08:49 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*sl_load_asset(t_mlx *mlx, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->mlx = mlx->mlx;
	img->path = path;
	img->img = mlx_png_file_to_image(img->mlx, img->path,
			&img->len, &img->height);
	return (img);
}

static void	sl_free_img(void *mlx, t_img *img)
{
	if (img->img)
		mlx_destroy_image(mlx, img->img);
	free (img);
}

t_pack	*sl_free_pack(void *mlx, t_pack *src)
{
	if (src->entry)
		sl_free_img(mlx, src->entry);
	if (src->exit)
		sl_free_img(mlx, src->exit);
	if (src->item)
		sl_free_img(mlx, src->item);
	if (src->wall)
		sl_free_img(mlx, src->wall);
	if (src->player)
		sl_free_img(mlx, src->player);
	return (0);
}

int	sl_load_assets(t_mlx *mlx)
{
	t_pack	*src;

	src = mlx->sources;
	src->entry = 0;
	src->exit = sl_load_asset(mlx, "./assets/exit.png");
	src->item = sl_load_asset(mlx, "./assets/item.png");
	src->wall = sl_load_asset(mlx, "./assets/wall.png");
	src->player = sl_load_asset(mlx, "./assets/player.png");
	if (!src->exit->img || !src->wall->img
		|| !src->item->img || !src->player->img)
	{
		src = sl_free_pack(mlx->mlx, src);
		return (0);
	}
	return (1);
}
