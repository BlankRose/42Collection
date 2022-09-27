/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:10:44 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/30 14:52:52 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_image	*cb_load_asset(t_cub *cub, char *path)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	img->img = 0;
	if (ft_endswith(path, ".png"))
		img->img = mlx_png_file_to_image(cub->mlx_ptr, path,
				&img->width, &img->height);
	else if (ft_endswith(path, ".xpm"))
		img->img = mlx_xpm_file_to_image(cub->mlx_ptr, path,
				&img->width, &img->height);
	if (img->img)
		img->pick = cb_convert_img(img);
	else
		ft_error(5);
	return (img);
}

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img -> addr + (y * img -> line_length + x * (img -> bpp / 8));
	*(int *)pixel = color;
}

void	ft_drawplayer(t_cub *cub)
{
	t_image	*img;

	img = malloc(sizeof(*img));
	img -> img = mlx_new_image(cub ->mlx_ptr, S_WIDTH, S_HEIGHT);
	img -> addr = mlx_get_data_addr(img -> img,
			&(img -> bpp), &(img -> line_length), &(img -> endian));
	cub -> image = img;
	cb_raycast(cub);
	cb_drawmap2d(cub);
	cb_drawplayerpoint(0x00FFFB000, cub);
	mlx_put_image_to_window(cub -> mlx_ptr, cub -> mlx_win,
		cub -> image -> img, 0, 0);
}

void	ft_drawline(t_dvector2 p1, t_dvector2 p2, t_cub *cub)
{
	float	dx;
	float	dy;
	int		max;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	max = ft_max1(ft_mod1(dx), ft_mod1(dy));
	dx /= max;
	dy /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		if ((int)p1.y < S_HEIGHT && (int)p1.y > 0
			&& (int)p1.x > 0 && (int)p1.x < S_WIDTH)
			img_pix_put(cub -> image, (int)p1.y, (int)p1.x,
				0x00FFFBB0);
		p1.x += dx;
		p1.y += dy;
	}
}

void	cb_drawvertline(double x, t_vector2 draw, int color, t_cub *cub)
{
	t_dvector2	v;
	double		step;
	int			start;
	int			y;

	v.x = 0.0;
	step = S_WIDTH / cub->mapx;
	x *= step;
	while (x + v.x < x + (step * PRECISION) && x < S_WIDTH)
	{
		y = 0;
		start = draw.x;
		while (y < start)
			img_pix_put(cub->image, (int)(x + v.x), y++, cub->c_col);
		while (start < draw.y)
			img_pix_put(cub -> image, (int)(x + v.x), start++, color);
		y = start;
		while (y < S_HEIGHT)
			img_pix_put(cub->image, (int)(x + v.x), y++, cub->f_col);
		v.x += PRECISION;
	}
}
