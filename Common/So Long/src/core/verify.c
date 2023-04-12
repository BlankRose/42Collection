/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:23:11 by flcollar          #+#    #+#             */
/*   Updated: 2023/04/12 14:00:46 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

typedef void	*(*t_new_ft)(void *);

static int		sl_check_tile(t_list *lt, t_map *map, size_t *i);
static void		sl_define_tile(t_list *lt, t_map *map, size_t *i);
static int		sl_check_path(t_map *map, t_list *data, t_vector2 pos);
static int		sl_last_check(t_map *map);

/**
 * Verify the integrality of the given map
 * and returns SUCCESS or FAILURE deponding if
 * it has the following attributes:
 * 
 * - Rectangular map with no gaps
 * - Only contains valid tiles (from TILE_SET)
 * - Player can play and finish it
 * */
int	sl_check_map(t_map *map)
{
	size_t		i;
	t_list		*lt;

	if (!map->data || !map->name || !map->player)
		return (FAILURE);
	lt = map->data;
	while (lt)
	{
		i = 0;
		while (((char *) lt->content)[i] && ((char *) lt->content)[i] != '\n')
			if (sl_check_tile(lt, map, &i))
				return (FAILURE);
		if (map->length && i != map->length)
			return (sl_error(4, map->name));
		map->length = i;
		lt = lt->next;
		map->height++;
	}
	return (sl_last_check(map));
}

/**
 * Checks a given singular row
 * */
static int	sl_check_tile(t_list *lt, t_map *map, size_t *i)
{
	char	*tmp;
	int		err;

	err = FALSE;
	tmp = lt->content;
	if ((map->height == 0 || ft_lstsize(lt) == 1) && tmp[*i] != TILE_SET[0])
		err = sl_error(6, map->name);
	else if ((i == 0 || *i == ft_strlenlimit(tmp, '\n') - 1)
		&& tmp[*i] != TILE_SET[0])
		err = sl_error(6, map->name);
	else if (!ft_isset(tmp[*i], TILE_SET))
		err = sl_error(3, map->name);
	sl_define_tile(lt, map, i);
	(*i)++;
	return (err);
}

/**
 * Changes some attributes stored in MAP depending on given tile
 * */
static void	sl_define_tile(t_list *lt, t_map *map, size_t *i)
{
	char	*tmp;

	tmp = lt->content;
	if (tmp[*i] == TILE_SET[2])
	{
		if (map->entry)
			tmp[*i] = '0';
		else
		{
			map->player->x = *i;
			map->player->y = map->height;
			map->player->z = 0;
		}
		map->entry++;
	}
	if (tmp[*i] == TILE_SET[3])
		map->exit++;
	if (tmp[*i] == TILE_SET[4])
		map->items++;
}

/**
 * Checks if there's a valid path
 * */
static int	sl_check_path(t_map *map, t_list *data, t_vector2 pos)
{
	t_list		*ln;
	t_string	tmp;

	ln = ft_lstlocate(data, pos.y);
	if (!ln)
		return (SUCCESS);
	tmp = ln->content;
	if (tmp[pos.x] && tmp[pos.x] != TILE_SET[0]
		&& tmp[pos.x] != TILE_SET[5] && tmp[pos.x] != TILE_ALT)
	{
		if (tmp[pos.x] == TILE_SET[3])
			map->verify.x++;
		if (tmp[pos.x] == TILE_SET[4])
			map->verify.y++;
		tmp[pos.x] = TILE_ALT;
		if (sl_check_path(map, data, ft_vector2_new(pos.x + 1, pos.y))
			|| sl_check_path(map, data, ft_vector2_new(pos.x - 1, pos.y))
			|| sl_check_path(map, data, ft_vector2_new(pos.x, pos.y + 1))
			|| sl_check_path(map, data, ft_vector2_new(pos.x, pos.y - 1)))
			return (FAILURE);
	}
	return (SUCCESS);
}

/**
 * Checks if the content generated during the
 * verification process is also valid to finalize
 * */
static int	sl_last_check(t_map *map)
{
	t_list	*dupl;
	t_list	*cur;

	if (!map->entry || !map->exit || !map->items)
		return (sl_error(5, map->name));
	if (map->length * TILE_SIZE >= MAX_WIDTH
		|| map->height * TILE_SIZE >= MAX_HEIGHT)
		return (sl_error(10, map->name));
	cur = map->data;
	dupl = NULL;
	while (cur)
	{
		ft_lstadd_back(&dupl, ft_lstdup(cur, (t_new_ft) ft_strdup));
		cur = cur->next;
	}
	if (!dupl || sl_check_path(map, dupl, \
			ft_vector2_new(map->player->x, map->player->y))
		|| !map->verify.x || map->verify.y != map->items)
		return (sl_error(11, map->name));
	ft_lstclear(&dupl, free);
	return (SUCCESS);
}
