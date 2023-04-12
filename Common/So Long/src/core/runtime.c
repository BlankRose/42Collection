/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:29:53 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/24 11:00:12 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_move_tile(t_ctx *ctx, t_vector2 pos, t_vec3 *ply)
{
	char		*str_ply;
	char		*str_pos;

	str_pos = ft_lstlocate(ctx->map->data, pos.y)->content;
	str_ply = ft_lstlocate(ctx->map->data, ply->y)->content;
	if (str_pos[pos.x] == TILE_SET[4])
		ft_printf(1, "Item Collected (%d / %d)!\n", ++ply->z, ctx->map->items);
	else if (str_pos[pos.x] == TILE_SET[3] && ply->z >= ctx->map->items)
	{
		ft_printf(1, "%sCompleted the map in %d moves!\n%s",
			BOLD, ctx->map->moves, FONTLESS);
		sl_exit_hook(ctx);
	}
	else if (str_pos[pos.x] == TILE_SET[5])
	{
		ft_printf(1, "%s%sGame Over! The cat got wet!\n%s",
			BOLD, RED, FONTLESS);
		sl_exit_hook(ctx);
	}
	if (str_ply[ply->x] == TILE_ALT)
		str_ply[ply->x] = TILE_SET[3];
	else
		str_ply[ply->x] = TILE_SET[1];
	return (0);
}

void	sl_move_player(t_ctx *ctx, t_vector2 pos)
{
	char			*str_ply;
	char			*str_pos;
	t_vec3			*ply;

	ply = ctx->map->player;
	str_pos = ft_lstlocate(ctx->map->data, pos.y)->content;
	str_ply = ft_lstlocate(ctx->map->data, ply->y)->content;
	if (str_pos[pos.x] == TILE_SET[0])
		return ;
	if (sl_move_tile(ctx, pos, ply))
		return ;
	if (str_pos[pos.x] == TILE_SET[3])
		str_pos[pos.x] = TILE_ALT;
	else
		str_pos[pos.x] = TILE_SET[2];
	ply->x = pos.x;
	ply->y = pos.y;
	++ctx->map->moves;
	mlx_clear_window(ctx->fw->mlx, ctx->fw->win);
	sl_load_region(ctx);
}

/**
 * Display the move and item counter on the screen
 * */
static void	sl_print_moves(t_ctx *ctx)
{
	t_string	str;

	str = ft_strdup("Items: ");
	str = ft_strexpend(str, ft_itoa(ctx->map->player->z), TRUE);
	str = ft_strexpend(str, " / ", FALSE);
	str = ft_strexpend(str, ft_itoa(ctx->map->items), TRUE);
	mlx_string_put(ctx->fw->mlx, ctx->fw->win, 2, 14,
		0xFFFFFFFF, str);
	free(str);
	str = ft_strdup("Moves: ");
	str = ft_strexpend(str, ft_itoa(ctx->map->moves), TRUE);
	mlx_string_put(ctx->fw->mlx, ctx->fw->win, 2, 28,
		0xFFFFFFFF, str);
	free(str);
}

/**
 * Display the region on screen, using the
 * given context as a reference
 * */
void	sl_load_region(t_ctx *ctx)
{
	t_list		*map;
	t_img		*img;
	t_vector3	pos;

	map = ctx->map->data;
	pos = ft_vector3_new(0, 0, 0);
	while (map)
	{
		pos.x = 0;
		if ((size_t) pos.y > ctx->map->height / 2)
			pos.z = 1;
		while (((char *) map->content)[pos.x])
		{
			img = ctx->pack->get_asset(ctx->pack,
					((char *) map->content)[pos.x], ctx->map->frame);
			ctx->fw->put_tile(ctx->fw, img, pos.x++, pos.y);
		}
		pos.y++;
		map = map->next;
	}
	sl_print_moves(ctx);
}
