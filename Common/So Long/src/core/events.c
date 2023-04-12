/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:45:59 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/23 19:39:07 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit_hook(t_ctx *ctx)
{
	exit(sl_clear(ctx->fw, ctx->map, ctx->pack));
	return (SUCCESS);
}

int	sl_loop_hook(t_ctx *ctx)
{
	static int		i;

	if (++i > 2000)
	{
		i = 0;
		if (ctx->map->frame >= 2)
			ctx->map->frame = 0;
		else
			ctx->map->frame++;
		mlx_clear_window(ctx->fw->mlx, ctx->fw->win);
		sl_load_region(ctx);
	}
	return (SUCCESS);
}

int	sl_key_hook(int keycode, t_ctx *ctx)
{
	t_vec3	*ply;

	ply = ctx->map->player;
	if (keycode == KEY_W || keycode == KEY_ARROW_UP)
		sl_move_player(ctx, ft_vector2_new(ply->x, ply->y - 1));
	else if (keycode == KEY_A || keycode == KEY_ARROW_LEFT)
		sl_move_player(ctx, ft_vector2_new(ply->x - 1, ply->y));
	else if (keycode == KEY_S || keycode == KEY_ARROW_DOWN)
		sl_move_player(ctx, ft_vector2_new(ply->x, ply->y + 1));
	else if (keycode == KEY_D || keycode == KEY_ARROW_RIGHT)
		sl_move_player(ctx, ft_vector2_new(ply->x + 1, ply->y));
	else if (keycode == KEY_ESC)
		sl_exit_hook(ctx);
	else if (keycode == KEY_ENTER)
		mlx_destroy_window(ctx->fw->mlx, ctx->fw->win);
	return (SUCCESS);
}
