/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:25:30 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/29 22:13:57 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_image	*cb_getwall(t_cub *cub, t_raycast *ray)
{
	if (ray->side == 0)
		return (cub->no);
	if (ray->side == 1)
		return (cub->we);
	if (ray->side == 2)
		return (cub->so);
	return (cub->ea);
}

static void	cb_drawtextline_loop(
	t_cub *cub, int line_height, t_raycast *ray, t_image *display)
{
	while (ray->w.y < ray->w.x)
		img_pix_put(cub->image, (int)(ray->tpos.y + ray->v.x), \
		ray->w.y++, cub->c_col);
	ray->t_step.x = 1.0 * display->width / line_height;
	ray->tpos.x = (ray -> draw.x - S_HEIGHT / 2 + \
		line_height / 2) * ray->t_step.x;
	while (ray->w.x < ray->draw.y)
	{
		ray->text.y = (int)ray->tpos.x & (display->width - 1);
		ray->tpos.x += ray->t_step.x;
		img_pix_put(cub->image, (int)(ray->tpos.y + ray->v.x), ray->w.x, \
			(int) display->pick[ray->text.y][ray->text.x]);
		ray->w.x++;
	}
	ray->w.y = ray->w.x;
	while (ray->w.y < S_HEIGHT)
		img_pix_put(cub->image, (int)(ray->tpos.y + ray->v.x), \
		ray->w.y++, cub->f_col);
}

void	cb_drawtextline(
	t_cub *cub, int line_height, t_raycast *ray)
{
	t_image		*display;

	display = cb_getwall(cub, ray);
	if (ray -> side == 0 && ray -> raydir.x > 0)
		ray->text.x = display->width - ray->text.x - 1;
	if (ray -> side == 1 && ray -> raydir.y < 0)
		ray->text.x = display->width - ray->text.x - 1;
	while (ray->tpos.y + ray->v.x < ray->tpos.y + \
		(ray->t_step.y * PRECISION) && ray->tpos.y < S_WIDTH)
	{
		ray->w.y = 0;
		ray->w.x = ray -> draw.x;
		cb_drawtextline_loop(cub, line_height, ray, display);
		ray->v.x += PRECISION;
	}
}
