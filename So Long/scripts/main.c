/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:51:16 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/25 15:56:42 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int c, char **args)
{
	t_map	map;
	t_mlx	mlx;
	t_ply	ply;

	if (c < 2)
		return (sl_error(0, 0));
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (sl_error(7, 0));
	while (*(++args))
	{
		if (ft_endswith(*args, ".ber"))
		{
			map = sl_map_init(sl_load_map(*args), *args);
			if (map.data && sl_check_map(&map, &ply))
				ft_lstclear(&map.data, free);
			if (!map.data)
				continue ;
			ft_printf(1, "%s%sSuccessfully loaded map: [%s]\n%s",
				GREEN, BOLD, map.name, FONTLESS);
			sl_start(&mlx, &map, &ply);
		}
		else
			sl_error(1, *args);
	}
}
