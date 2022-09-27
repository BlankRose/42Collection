/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:38:13 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/30 14:16:32 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int	cub_convert_bits(t_byte *raw)
{
	int	i;

	i = 3;
	return (cb_getrgb(raw[i - 1], raw[i - 2], raw[i - 3]));
}

t_uint	**cb_convert_img(t_image *img)
{
	t_vector3	v;
	t_uint		**picker;
	char		*raw;

	raw = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, \
		&img->endian);
	v = ft_vector3_new(0, 0, img->line_length / \
		(img->width * (64 / img->width)));
	if (!raw)
		return (0);
	picker = malloc(sizeof(t_uint *) * img->height);
	while (v.y < img->height)
	{
		v.x = 0;
		picker[v.y] = malloc(sizeof(t_uint) * img->width);
		while (v.x < img->width)
		{
			picker[v.y][v.x] = cub_convert_bits((unsigned char *) \
				&raw[v.y * (img->line_length) + v.x * v.z]);
			v.x++;
		}
		v.y++;
	}
	return (picker);
}

int	cb_setcolor(char *arg, int red, int green, int blue)
{
	char	**splited;
	int		rgb;

	splited = ft_split(arg, ',');
	if (cb_arraylen(splited) != 3)
	{
		ft_freemem(splited);
		free(arg);
		return (-1);
	}
	red = ft_atoi(splited[0]);
	green = ft_atoi(splited[1]);
	blue = ft_atoi(splited[2]);
	if (red > 255 || green > 255 || blue > 255)
	{
		ft_freemem(splited);
		free(arg);
		return (-1);
	}
	rgb = cb_getrgb(red, green, blue);
	ft_freemem(splited);
	free(arg);
	return (rgb);
}

int	cb_isspaceline(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (!ft_isspace(line[i]))
			return (0);
	return (1);
}

int	cb_isparamline(char *line)
{
	char	**args;

	if (cb_isspaceline(line))
		return (1);
	args = ft_split(line, ' ');
	if ((!ft_strncmp(args[0], "NO", 3) || !ft_strncmp(args[0], "SO", 3) \
		|| !ft_strncmp(args[0], "EA", 3) || !ft_strncmp(args[0], "WE", 3) \
		|| !ft_strncmp(args[0], "F", 2) || !ft_strncmp(args[0], "C", 2))
		&& args[1])
	{
		ft_freemem(args);
		return (1);
	}
	ft_freemem(args);
	return (0);
}
