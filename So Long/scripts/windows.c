/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:59:10 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/25 18:13:24 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_new_window(t_mlx *mlx, t_map *map)
{
	mlx->win_len = map->len * TILE_SIZE * WIN_RATIO;
	mlx->win_height = map->height * TILE_SIZE * WIN_RATIO;
	mlx->window = mlx_new_window(mlx->mlx, mlx->win_len,
			mlx->win_height, TITLE);
}

static t_all	sl_all_init(t_mlx *mlx, t_map *map, t_ply *player)
{
	t_all	all;

	all.map = map;
	all.mlx = mlx;
	all.ply = player;
	return (all);
}

int	sl_start(t_mlx *mlx, t_map *map, t_ply *ply)
{
	t_all	all;

	sl_new_window(mlx, map);
	all = sl_all_init(mlx, map, ply);
	if (!mlx->window)
		return (sl_error(8, map->name));
	if (!sl_load_assets(mlx))
		return (sl_error(9, 0));
	mlx_key_hook(mlx->window, sl_key_hook, &all);
	mlx_hook(mlx->window, 17, 1L << 0, sl_close, &all);
	sl_load_region(&all);
	mlx_loop(mlx->mlx);
	return (0);
}
