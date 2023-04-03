/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:02:41 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/28 19:30:11 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		ft_error(1);
	cub = cb_initcube();
	if (!cub)
		ft_error(3);
	cb_parsemap(argv[1], cub, -1, NULL);
	cb_initminimap(cub);
	cb_mlx_launch(cub);
	return (0);
}
