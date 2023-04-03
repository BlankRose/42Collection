/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:47:34 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/25 12:42:13 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_error_msg(int err, char *s)
{
	if (err == 0)
		ft_printf(2, "Please provide atleast one map!");
	else if (err == 1)
		ft_printf(2, "is not a .ber file!");
	else if (err == 2)
		ft_printf(2, "couldn't be loaded or couldn't be found!");
	else if (err == 3)
		ft_printf(2, "contains a non-valid tiles!");
	else if (err == 4)
		ft_printf(2, "is not a rectangular shape!");
	else if (err == 5)
		ft_printf(2, "is missing an exit, entrance or collectible tile!");
	else if (err == 6)
		ft_printf(2, "walls aren't completely surrounding the gameplay area!");
	else if (err == 7)
		ft_printf(2, "MiniLibX failed to initialize!");
	else if (err == 8)
		ft_printf(2, "Window couldn't be loaded properly for the map [%s]!", s);
	else if (err == 9)
		ft_printf(2, "Couldn't load the requiered assets!");
	else
		ft_printf(2, "An unknown error occured!");
}

int	sl_error(int err, char *extra)
{
	ft_printf(2, "%s%sError: ", BOLD, RED);
	if (err >= 1 && err <= 6)
		ft_printf(2, "The map [%s] ", extra);
	sl_error_msg(err, extra);
	ft_printf(2, "\n%s%s%s%s", RESETFONT, ITALIC, RED, DARK);
	if (err < 2)
		ft_printf(2, "Syntax: ./%s <maps.ber> [more maps..]\n", NAME);
	ft_printf(2, "%s", RESETFONT);
	return (1);
}
