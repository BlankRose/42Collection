/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:53:21 by flcollar          #+#    #+#             */
/*   Updated: 2023/04/12 14:04:02 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * SO_LONG: AFTERMATH
 * 
 * This is mostly a joke project at this point.
 * It was purposely made with a CPP style (using pure C),
 * respecting the defined rules of the original subject.
 * */
int	main(int c, t_string *args)
{
	t_fw	*fw;
	t_map	*map;
	t_pack	*pack;

	if (sl_prepare(c, &fw, &map, &pack))
		return (del_framework(fw), del_map(map),
			del_pack(pack), FAILURE);
	while (*(++args))
	{
		if (!ft_endswith(*args, ".ber"))
		{
			sl_error(1, *args);
			continue ;
		}
		if (!map->load_map(map, *args))
			continue ;
		sl_success(*args);
		sl_start(fw, map, pack);
		map->unload_map(map);
	}
	return (sl_clear(fw, map, pack));
}
