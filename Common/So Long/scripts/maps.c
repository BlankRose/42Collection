/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:51:32 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/25 17:16:36 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	sl_map_init(t_list *lst, char *name)
{
	t_map	map;

	map.height = 0;
	map.len = 0;
	map.item = 0;
	map.in = 0;
	map.out = 0;
	map.data = lst;
	map.name = name;
	return (map);
}

t_list	*sl_load_map(char *str)
{
	t_list	*lst;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		sl_error(2, str);
		return (0);
	}
	lst = get_all_lines(fd);
	close(fd);
	return (lst);
}

static void	sl_check_tile2(t_list *lst, t_map *map, t_ply *ply, size_t *i)
{
	char	*tmp;

	tmp = lst->content;
	if (tmp[*i] == TILE_SET[2])
	{
		if (map->in)
			tmp[*i] = '0';
		else
		{
			ply->x = *i;
			ply->y = map->height;
			ply->item = 0;
		}
		map->in++;
	}
	if (tmp[*i] == TILE_SET[3])
		map->out++;
	if (tmp[*i] == TILE_SET[4])
		map->item++;
}

static int	sl_check_tile(t_list *lst, t_map *map, t_ply *ply, size_t *i)
{
	char	*tmp;
	int		err;

	err = FALSE;
	tmp = lst->content;
	if ((map->height == 0 || ft_lstsize(lst) == 1) && tmp[*i] != TILE_SET[0])
		err = sl_error(6, map->name);
	else if ((i == 0 || *i == ft_strlenlimit(tmp, '\n') - 1)
		&& tmp[*i] != TILE_SET[0])
		err = sl_error(6, map->name);
	else if (!ft_isset(tmp[*i], TILE_SET))
		err = sl_error(3, map->name);
	sl_check_tile2(lst, map, ply, i);
	(*i)++;
	return (err);
}

int	sl_check_map(t_map *map, t_ply *ply)
{
	size_t		i;
	t_list		*lst;
	char		*tmp;

	if (!map->data || !map->name)
		return (1);
	lst = map->data;
	while (lst)
	{
		i = 0;
		tmp = lst->content;
		while (tmp[i] && tmp[i] != '\n')
			if (sl_check_tile(lst, map, ply, &i))
				return (1);
		if (map->len && i != map->len)
			return (sl_error(4, map->name));
		map->len = i;
		lst = lst->next;
		map->height++;
	}
	if (!map->in || !map->out || !map->item)
		return (sl_error(5, map->name));
	return (0);
}
