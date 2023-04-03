/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:49:06 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/29 19:33:36 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

// SIDES:
//
// 0 *- Forward
// 1 *- Backward
// 2 *- Left
// 3 *- Right

void	cb_movement(int side, t_cub *cub)
{
	t_ply	*ply;

	ply = cub->player;
	if (side == 0)
	{
		if (cub->map[(int)(ply->pos.x + ply->dir.x * MOVE_SPD)] \
			[(int)(ply->pos.y)] != '1')
			ply->pos.x += ply->dir.x * MOVE_SPD;
		if (cub->map[(int)(ply->pos.x)][(int)(ply->pos.y + \
			ply->dir.y * MOVE_SPD)] != '1')
			ply->pos.y += ply->dir.y * MOVE_SPD;
	}
	if (side == 1)
	{
		if (cub->map[(int)(ply->pos.x - ply->dir.x * MOVE_SPD)] \
			[(int)(ply->pos.y)] != '1')
			ply->pos.x -= ply->dir.x * MOVE_SPD;
		if (cub->map[(int)(ply->pos.x)][(int)(ply->pos.y - \
			ply->dir.y * MOVE_SPD)] != '1')
			ply->pos.y -= ply->dir.y * MOVE_SPD;
	}
}

void	cb_move_sides(int side, t_cub *cub)
{
	t_ply	*ply;

	ply = cub->player;
	if (side == 3)
	{
		if (cub->map[(int)(ply->pos.x + ply->plane.x * MOVE_SPD)] \
			[(int)(ply->pos.y)] != '1')
			ply->pos.x += ply->plane.x * MOVE_SPD;
		if (cub->map[(int)(ply->pos.x)][(int)(ply->pos.y + \
			ply->plane.y * MOVE_SPD)] != '1')
			ply->pos.y += ply->plane.y * MOVE_SPD;
	}
	if (side == 2)
	{
		if (cub->map[(int)(ply->pos.x - ply->plane.x * MOVE_SPD)] \
			[(int)(ply->pos.y)] != '1')
			ply->pos.x -= ply->plane.x * MOVE_SPD;
		if (cub->map[(int)(ply->pos.x)][(int)(ply->pos.y - \
			ply->plane.y * MOVE_SPD)] != '1')
			ply->pos.y -= ply->plane.y * MOVE_SPD;
	}
}

void	cb_camera(int side, t_cub *cub, double spd)
{
	t_ply	*ply;
	double	old_dirx;
	double	old_planex;
	double	rot_spd;

	ply = cub->player;
	old_dirx = ply->dir.x;
	old_planex = ply->plane.x;
	rot_spd = ROT_SPD * spd;
	if (side == 2)
		rot_spd = -ROT_SPD * spd;
	ply->dir.x = ply->dir.x * cos(rot_spd) - ply->dir.y * sin(rot_spd);
	ply->dir.y = old_dirx * sin(rot_spd) + ply->dir.y * cos(rot_spd);
	ply->plane.x = ply->plane.x * cos(rot_spd) - \
	ply->plane.y * sin(rot_spd);
	ply->plane.y = old_planex * sin(rot_spd) + \
	ply->plane.y * cos(rot_spd);
}
