/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:22:45 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/30 15:00:34 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	cb_refresh_window(t_cub *cub)
{
	mlx_destroy_image(cub->mlx_ptr, cub->image->img);
	free(cub->image);
	mlx_clear_window(cub->mlx_ptr, cub->mlx_win);
	ft_drawplayer(cub);
}

static int	mlx_exit_handler(void *param)
{
	cb_exit(0, (t_cub *) param);
	return (0);
}

static int	mlx_key_handler(int key, t_cub *cub)
{
	t_ply	*ply;

	ply = cub -> player;
	if (key == KEY_ESC)
		cb_exit(0, cub);
	else if (key == KEY_W || key == KEY_ARROW_UP)
		cb_movement(0, cub);
	else if (key == KEY_S || key == KEY_ARROW_DOWN)
		cb_movement(1, cub);
	else if (key == KEY_A)
		cb_move_sides(2, cub);
	else if (key == KEY_D)
		cb_move_sides(3, cub);
	else if (key == KEY_ARROW_RIGHT)
		cb_camera(2, cub, 1.0);
	else if (key == KEY_ARROW_LEFT)
		cb_camera(3, cub, 1.0);
	else
		return (1);
	cb_refresh_window(cub);
	return (0);
}

static int	mlx_motion_handler(int x, int y, t_cub *cub)
{
	if (cub -> m_pos.x == INT32_MIN && cub -> m_pos.y == INT32_MIN
		&& x >= 0 && x <= S_WIDTH && y >= 0 && y <= S_HEIGHT)
	{
		cub -> m_pos.x = x;
		cub -> m_pos.y = y;
	}
	else if (!(x >= 0 && x <= S_WIDTH && y >= 0 && y <= S_HEIGHT))
		mlx_mouse_show();
	else if (cub -> m_pos.x != INT32_MIN && cub -> m_pos.y != INT32_MIN
		&& x >= 0 && x <= S_WIDTH && y >= 0 && y <= S_HEIGHT)
	{
		mlx_mouse_hide();
		if (x < (S_WIDTH / 4))
			cb_camera(3, cub, 0.3);
		else if (x > (S_WIDTH * 3) / 4)
			cb_camera(2, cub, 0.3);
		else
			return (0);
		cub -> m_pos.x = x;
		cub -> m_pos.y = y;
		cb_refresh_window(cub);
		return (y);
	}
	return (y);
}

void	cb_mlx_launch(t_cub *cub)
{
	ft_drawplayer(cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, mlx_key_handler, cub);
	mlx_hook(cub->mlx_win, 17, 1L << 0, mlx_exit_handler, cub);
	mlx_hook(cub->mlx_win, 6, 1L << 6, mlx_motion_handler, cub);
	mlx_loop(cub->mlx_ptr);
}
