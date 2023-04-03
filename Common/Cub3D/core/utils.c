/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:02:56 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/30 14:52:21 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	cb_exit(int exitcode, t_cub *cub)
{
	if (cub)
	{
		ft_freemem(cub->map);
		free(cub->ea);
		free(cub->so);
		free(cub->we);
		free(cub->no);
	}
	exit (exitcode);
}

void	ft_error(int flag)
{
	ft_printf(2, "Error\n");
	if (flag == 1)
		ft_printf(2, "Invalid argument: give only one valid \
path to the map file!\n");
	if (flag == 2)
		ft_printf(2, "Argument: give only one valid path to \
the map file!\n");
	if (flag == 3)
		ft_printf(2, "Failed to load settings!\n");
	if (flag == 4)
		ft_printf(2, "The map is invalid!\n");
	if (flag == 5)
		ft_printf(2, "Invalid path to texture!\n");
	exit(1);
}

void	ft_freemem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

int	cb_getrgb(int red, int green, int blue)
{
	int	rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

int	cb_arraylen(char **arr)
{
	int		i;

	i = 0;
	if (!arr)
		return (i);
	while (arr[i])
		i++;
	return (i);
}
