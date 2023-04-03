/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:44:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/28 19:18:23 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	cb_drawplayerpoint_extention(int color, t_cub *cub, t_dvector2 va)
{
	t_dvector2	vi;
	t_dvector2	vb;

	vi.x = 0.0;
	vb.x = cub -> player -> pos.x * S_PIXEL + 2;
	vb.y = cub -> player -> pos.y * S_PIXEL + 2;
	while ((va.x + vi.x) < vb.x)
	{
		vi.y = 0.0;
		while ((va.y + vi.y) < vb.y)
		{
			img_pix_put(cub -> image, va.y + vi.y, va.x + vi.x, color);
			vi.y++;
		}
		vi.x++;
	}
}

void	cb_drawplayerpoint(int color, t_cub *cub)
{
	t_dvector2	v;
	t_dvector2	p1;
	t_dvector2	p2;

	v.x = cub -> player -> pos.x * S_PIXEL - 2;
	v.y = cub -> player -> pos.y * S_PIXEL - 2;
	p1.x = cub -> player -> pos.x * S_PIXEL;
	p1.y = cub -> player -> pos.y * S_PIXEL;
	p2.x = p1.x + cub -> player -> dir.x * S_PIXEL;
	p2.y = p1.y + cub -> player -> dir.y * S_PIXEL;
	ft_drawline(p1, p2, cub);
	cb_drawplayerpoint_extention(color, cub, v);
}

void	cb_drawrectangle(int x, int y, int color, t_cub *cub)
{
	int	i;
	int	j;
	int	x1;
	int	y1;

	i = 0;
	x1 = x + S_PIXEL;
	y1 = y + S_PIXEL;
	while ((x + i) < x1)
	{
		j = 0;
		while ((y + j) < y1)
		{
			img_pix_put(cub -> image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	cb_drawmap2d(t_cub *cub)
{
	int			color;
	t_vector2	v;
	t_vector2	o;

	v.y = 0;
	while (cub->map[v.y] && v.y < cub -> mapy)
	{
		v.x = 0;
		while (cub->map[v.y][v.x] && v.x < cub -> mapx)
		{
			o.x = v.x * S_PIXEL;
			o.y = v.y * S_PIXEL;
			if (cub->map[v.y][v.x] == '1')
				color = 0x00FFFFFF;
			if (cub->map[v.y][v.x] == '0')
				color = 0x00999999;
			if (ft_isset(cub->map[v.y][v.x], "NSWE"))
				color = 0x00AAFFB0;
			if (ft_isset(cub->map[v.y][v.x++], "10NSWE"))
				cb_drawrectangle(o.x, o.y, color, cub);
		}
		v.y++;
	}
}
