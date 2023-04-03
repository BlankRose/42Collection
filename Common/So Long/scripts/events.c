/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:23:25 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/25 18:48:29 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_close(t_all *all)
{
	mlx_destroy_window(all->mlx->mlx, all->mlx->window);
	sl_free_pack(all->mlx->mlx, all->mlx->sources);
	ft_lstclear(&all->map->data, free);
	exit(0);
	return (0);
}

static int	sl_move_tile(t_all *meta, t_vector2 pos, size_t count)
{
	char		*str_ply;
	char		*str_pos;

	str_pos = ft_lstlocate(meta->map->data, pos.y)->content;
	str_ply = ft_lstlocate(meta->map->data, meta->ply->y)->content;
	if (str_pos[pos.x] == TILE_SET[4])
	{
		ft_printf(1, "Item Collected!\n");
		meta->ply->item++;
	}
	else if (str_pos[pos.x] == TILE_SET[3]
		&& meta->ply->item == meta->map->item)
	{
		ft_printf(1, "%s=== CONGRATZ ===\nYou Won!\n", BOLD);
		ft_printf(1, "Total Moves: %d\n%s", ++count, FONTLESS);
		sl_close(meta);
		return (1);
	}
	if (str_ply[meta->ply->x] == 'X')
		str_ply[meta->ply->x] = TILE_SET[3];
	else
		str_ply[meta->ply->x] = TILE_SET[1];
	return (0);
}

void	sl_move_player(t_all *meta, t_vector2 pos)
{
	static size_t	count;
	char			*str_ply;
	char			*str_pos;

	str_pos = ft_lstlocate(meta->map->data, pos.y)->content;
	str_ply = ft_lstlocate(meta->map->data, meta->ply->y)->content;
	if (str_pos[pos.x] == TILE_SET[0])
		return ;
	if (sl_move_tile(meta, pos, count))
		return ;
	if (str_pos[pos.x] == TILE_SET[3])
		str_pos[pos.x] = 'X';
	else
		str_pos[pos.x] = TILE_SET[2];
	meta->ply->x = pos.x;
	meta->ply->y = pos.y;
	ft_printf(1, "%sMoves: %d\n%s", DARK, ++count, FONTLESS);
	mlx_clear_window(meta->mlx->mlx, meta->mlx->window);
	sl_load_region(meta);
}

static t_img	*sl_get_asset(char c, t_pack *src)
{
	if (c == TILE_SET[0])
		return (src->wall);
	if (c == TILE_SET[2] || c == 'X')
		return (src->player);
	if (c == TILE_SET[3])
		return (src->exit);
	if (c == TILE_SET[4])
		return (src->item);
	return (0);
}

void	sl_load_region(t_all *all)
{
	t_list		*map;
	t_img		*img;
	char		*str;
	t_vector3	pos;

	map = all->map->data;
	pos = ft_vector3_new(0, 0, 0);
	while (map)
	{
		pos.x = 0;
		str = map->content;
		while (str[pos.x])
		{
			img = sl_get_asset(str[pos.x], all->mlx->sources);
			if (img)
				mlx_put_image_to_window(all->mlx->mlx, all->mlx->window,
					img->img, TILE_SIZE * pos.x, TILE_SIZE * pos.y);
			pos.x++;
		}
		pos.y++;
		map = map->next;
	}
}
