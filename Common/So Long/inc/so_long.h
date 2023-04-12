/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:53:03 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/23 19:19:39 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Framework.h"
# include "Vector3.h"
# include "Assets.h"
# include "Map.h"

typedef struct s_Context{
	t_fw	*fw;
	t_pack	*pack;
	t_map	*map;
}	t_ctx;

int		sl_error(int err, t_string extra);
int		sl_success(t_string name);

t_bool	sl_prepare(t_int32 c, t_fw **fw, t_map **map, t_pack **pack);
t_bool	sl_clear(t_fw *fw, t_map *map, t_pack *pack);
int		sl_start(t_fw *fw, t_map *map, t_pack *pack);

int		sl_exit_hook(t_ctx *ctx);
int		sl_key_hook(int keycode, t_ctx *ctx);
int		sl_loop_hook(t_ctx *ctx);

void	sl_move_player(t_ctx *ctx, t_vector2 pos);
void	sl_load_region(t_ctx *ctx);

#endif /* SO_LONG_H */