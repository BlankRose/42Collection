/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkSpecial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:53:17 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/14 13:59:06 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_issign(int c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}
