/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:18:39 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/30 14:46:58 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	cb_initminimap(t_cub *cub)
{
	t_image	*img;

	img = malloc(sizeof(*img));
	img -> img = mlx_new_image(cub ->mlx_ptr, cub -> mapx * S_PIXEL, \
		cub -> mapy * S_PIXEL);
	img -> addr = mlx_get_data_addr(img -> img,
			&(img -> bpp), &(img -> line_length), &(img -> endian));
	cub -> minimap = img;
}

t_ply	*cb_initplayer(void)
{
	t_ply	*player;

	player = malloc(sizeof(*player));
	if (!player)
		return (NULL);
	player -> pa = 1;
	player -> pos.x = 0;
	player -> pos.y = 0;
	player -> dir.x = 0;
	player -> dir.y = 0;
	player -> plane.x = 0;
	player -> plane.y = 0.66;
	return (player);
}

t_cub	*cb_initcube(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(*cub));
	if (!cub)
		return (NULL);
	cub -> mlx_ptr = mlx_init();
	cub -> mlx_win = mlx_new_window(cub -> mlx_ptr, S_WIDTH, S_HEIGHT, "cub3d");
	cub -> player = cb_initplayer();
	cub -> ray = malloc(sizeof(t_raycast));
	cub -> c_col = 0;
	cub -> f_col = 0;
	cub -> time = 0;
	cub -> oldtime = 0;
	cub -> no = 0;
	cub -> so = 0;
	cub -> we = 0;
	cub -> ea = 0;
	cub -> m_pos.x = INT32_MIN;
	cub -> m_pos.y = INT32_MIN;
	return (cub);
}
