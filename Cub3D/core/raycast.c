/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:07:00 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/30 14:13:16 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

// static void	cb_raycast_finalize(t_cub *cub, t_raycast *ray)
// {
// 	int			color;
// 	int			line_height;
// 	double		wall_distance;
// 	t_vector2	draw;

// 	if (!ray->side)
// 		wall_distance = (ray->side_d.x - ray->delta_d.x);
// 	else
// 		wall_distance = (ray->side_d.y - ray->delta_d.y);
// 	line_height = (int)(S_HEIGHT / wall_distance);
// 	draw.x = -line_height / 2 + S_HEIGHT / 2;
// 	if (draw.x < 0)
// 		draw.x = 0;
// 	draw.y = line_height / 2 + S_HEIGHT / 2;
// 	if (draw.y >= S_HEIGHT)
// 		draw.y = S_HEIGHT - 1;
// 	color = 0x00FF00FF;
// 	if (ray->side)
// 		color = color / 2;
// 	cb_drawvertline(ray->pos.x, draw, color, cub);
// }

static void	cb_raycast_finalize(t_cub *cub, t_raycast *ray)
{
	int			line_height;
	double		wall_distance;
	double		wall_x;

	if (!(ray->side % 2))
		wall_distance = (ray->side_d.x - ray->delta_d.x);
	else
		wall_distance = (ray->side_d.y - ray->delta_d.y);
	line_height = (int)(S_HEIGHT / wall_distance);
	ray -> draw.x = -line_height / 2 + S_HEIGHT / 2;
	if (ray -> draw.x < 0)
		ray -> draw.x = 0;
	ray -> draw.y = line_height / 2 + S_HEIGHT / 2;
	if (ray -> draw.y >= S_HEIGHT)
		ray -> draw.y = S_HEIGHT - 1;
	if (ray -> side % 2 == 0)
		wall_x = cub -> player -> pos.y + (wall_distance * ray -> raydir.y);
	else
		wall_x = cub -> player -> pos.x + (wall_distance * ray -> raydir.x);
	wall_x -= floorf(wall_x);
	ray->text.x = (int)(wall_x * cb_getwall(cub, ray)->width);
	ray->t_step.y = S_WIDTH / cub->mapx;
	ray->tpos.y = ray->pos.x * ray->t_step.y;
	ray->v.x = 0.0;
	cb_drawtextline(cub, line_height, ray);
}

static void	cb_raycast_hit(t_cub *cub, t_raycast *ray)
{
	t_bool	hit;

	hit = FALSE;
	while (!hit)
	{
		if (ray->side_d.x < ray->side_d.y)
		{
			ray->side_d.x += ray->delta_d.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
			if (ray->step.x >= 0)
				ray->side = 2;
		}
		else
		{
			ray->side_d.y += ray->delta_d.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
			if (ray->step.y >= 0)
				ray->side = 3;
		}
		if (cub -> map[ray->map.x][ray->map.y] == '1')
			hit = TRUE;
	}
}

static void	cb_ray_init(t_raycast *ray, t_ply *player)
{
	ray->camerax = 2 * ray->pos.x / ray->pos.y - 1;
	ray->raydir.x = player -> dir.x + player -> plane.x * ray->camerax;
	ray->raydir.y = player -> dir.y + player -> plane.y * ray->camerax;
	ray->map.x = (int)(player -> pos.x);
	ray->map.y = (int)(player -> pos.y);
	ray->delta_d.x = 1e30;
	if (ray->raydir.x)
		ray->delta_d.x = cb_dabs(1 / ray->raydir.x);
	ray->delta_d.y = 1e30;
	if (ray->raydir.y)
		ray->delta_d.y = cb_dabs(1 / ray->raydir.y);
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->side_d.x = (player -> pos.x - ray->map.x) * ray->delta_d.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_d.x = (ray->map.x + 1.0 - player->pos.x) * ray->delta_d.x;
	}
}

void	cb_raycast(t_cub *cub)
{
	t_raycast	*ray;
	t_ply		*player;

	ray = cub->ray;
	ray->pos.x = 0;
	ray->pos.y = cub -> mapx;
	player = cub -> player;
	while (ray->pos.x <= ray->pos.y + 1)
	{
		cb_ray_init(ray, player);
		if (ray->raydir.y < 0)
		{
			ray->step.y = -1;
			ray->side_d.y = (player -> pos.y - ray->map.y) * ray->delta_d.y;
		}
		else
		{
			ray->step.y = 1;
			ray->side_d.y = (ray->map.y + 1.0 - player->pos.y) * ray->delta_d.y;
		}
		cb_raycast_hit(cub, ray);
		cb_raycast_finalize(cub, ray);
		ray->pos.x += PRECISION;
	}
}
