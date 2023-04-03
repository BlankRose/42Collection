/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:50:33 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/30 15:15:50 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	set_direction(t_cub *cub, char tile)
{
	if (tile == 'N')
		cub->player->dir.x = -1;
	if (tile == 'S')
	{
		cub->player->dir.x = -1;
		cub->player->plane.x = -cub->player->plane.x;
	}
	if (tile == 'E')
	{
		cub->player->dir.y = 1;
		cub->player->plane.x = cub->player->plane.y;
		cub->player->plane.y = 0;
	}
	if (tile == 'W')
	{
		cub->player->dir.y = -1;
		cub->player->plane.x = -cub->player->plane.y;
		cub->player->plane.y = 0;
	}
}

static int	get_value(t_cub *cub, int prev, int *start, t_vector2 v)
{
	if (cub->map[v.x][v.y] == '1')
		prev = 2;
	if (ft_isset(cub->map[v.x][v.y], "0NWES") && prev == 2)
		prev = 1;
	if (cub->map[v.x][v.y] == ' ' && prev == 2)
		prev = 0;
	if (start && ft_isset(cub->map[v.x][v.y], "NWES"))
	{
		*start += 1;
		cub->player->pos.x = v.x + 0.5;
		cub->player->pos.y = v.y + 0.5;
		set_direction(cub, cub->map[v.x][v.y]);
	}
	if (!ft_isset(cub->map[v.x][v.y], "10 NWES"))
		prev = -1;
	return (prev);
}

int	check_map(t_cub *cub, t_vector2 v, t_vector2 in)
{
	char	**map;

	map = cub->map;
	while (map[v.x])
	{
		v.y = 0;
		while (map[v.x][v.y] && map[v.x][v.y] != '\n')
		{
			in.x = get_value(cub, in.x, &in.y, ft_vector2_new(v.x, v.y));
			if ((in.x < 0) || (in.x == 1 && ft_isset(map[v.x][v.y + 1], " \n\0"))
				|| (in.x == 0 && ft_isset(map[v.x][v.y + 1], "0NWES"))
				|| (!map[v.x + 1] && !ft_isset(map[v.x][v.y], "1 "))
				|| (!v.x && ft_isset(map[v.x][v.y], "0NWES")))
				return (1);
			if (map[v.x + 1] && map[v.x + 1][v.y])
				if ((in.x == 1 && ft_isset(map[v.x + 1][v.y], " \n\0"))
					|| (in.x == 0 && ft_isset(map[v.x + 1][v.y], "0NWES")))
					return (1);
			v.y++;
		}
		v.x++;
	}
	if (in.y != 1)
		return (2);
	return (0);
}
