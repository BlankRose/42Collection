/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:34:47 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/25 18:14:25 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_hook(int keycode, t_all *param)
{
	t_ply	*ply;

	ply = param->ply;
	if (keycode == KEY_W || keycode == KEY_UP)
		sl_move_player(param, ft_vector2_new(ply->x, ply->y - 1));
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		sl_move_player(param, ft_vector2_new(ply->x - 1, ply->y));
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		sl_move_player(param, ft_vector2_new(ply->x, ply->y + 1));
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		sl_move_player(param, ft_vector2_new(ply->x + 1, ply->y));
	else if (keycode == KEY_ESC)
		sl_close(param);
	param = 0;
	return (0);
}
