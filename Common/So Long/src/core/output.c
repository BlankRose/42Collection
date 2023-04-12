/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:35:17 by flcollar          #+#    #+#             */
/*   Updated: 2023/04/12 13:28:35 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_error_msg2(int err, t_string s)
{
	if (err == 8)
		ft_printf(2, "Window couldn't be loaded properly for the map [%s]!", s);
	else if (err == 9)
		ft_printf(2, "Couldn't load the requiered assets!");
	else if (err == 10)
		ft_printf(2, "the map would exceed screen size!");
	else if (err == 11)
		ft_printf(2, "the map [%s] is impossible!", s);
	else
		ft_printf(2, "An unknown error occured!");
}

static void	sl_error_msg(int err, t_string s)
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
	else
		sl_error_msg2(err, s);
}

/**
 * Print the corresponding error message
 * along with additional message if given
 * 
 * @return		Returns FAILURE value (1)
 * */
int	sl_error(int err, t_string extra)
{
	ft_printf(2, "%s%sError: ", BOLD, RED);
	if (err >= 1 && err <= 6)
		ft_printf(2, "The map [%s] ", extra);
	sl_error_msg(err, extra);
	ft_printf(2, "\n%s%s%s%s", RESETFONT, ITALIC, RED, DARK);
	if (err < 2)
		ft_printf(2, "Syntax: ./%s <maps.ber> [more maps..]\n", NAME);
	ft_printf(2, "%s", RESETFONT);
	return (FAILURE);
}

/**
 * Print a success message along with
 * some debugging details when DEBUG is set
 * 
 * @return		Returns SUCCESS value (0)
 * */
int	sl_success(t_string name)
{
	ft_printf(1, "%s%sSuccessfully loaded map: [%s]\n%s",
		GREEN, BOLD, name, FONTLESS);
	return (SUCCESS);
}
