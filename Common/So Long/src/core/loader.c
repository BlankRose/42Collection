/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:00:42 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/26 11:10:29 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Prepares the software, by allocating the right
 * amount of memory and check for some basic needs
 * */
t_bool	sl_prepare(t_int32 c, t_fw **fw, t_map **map, t_pack **pack)
{
	if (c < 2)
		return (sl_error(0, NULL));
	*fw = new_framework();
	if (!*fw)
		return (sl_error(7, NULL));
	*pack = new_pack((*fw)->mlx);
	if (!*pack)
		return (sl_error(9, NULL));
	*map = new_map();
	if (!*map)
		return (sl_error(-1, NULL));
	return (SUCCESS);
}

/**
 * Clears the memory used by the software
 * to get ready to leave without leaks
 * */
t_bool	sl_clear(t_fw *fw, t_map *map, t_pack *pack)
{
	del_map(map);
	del_pack(pack);
	del_framework(fw);
	return (SUCCESS);
}

/**
 * Define its context for hooks
 * and runs the framework accordingly
 * */
int	sl_start(t_fw *fw, t_map *map, t_pack *pack)
{
	t_ctx	ctx;

	if (fw->new_window(fw, map->length * TILE_SIZE * WIN_RATIO, \
		map->height * TILE_SIZE * WIN_RATIO, "After SoLong"))
		return (sl_error(8, map->name));
	ctx.fw = fw;
	ctx.map = map;
	ctx.pack = pack;
	mlx_key_hook(fw->win, sl_key_hook, &ctx);
	mlx_loop_hook(fw->mlx, sl_loop_hook, &ctx);
	mlx_hook(fw->win, 17, 1L << 0, sl_exit_hook, &ctx);
	sl_load_region(&ctx);
	mlx_loop(fw->mlx);
	return (SUCCESS);
}
