/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:15:25 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/11 21:02:30 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_hasbit(t_byte byte, int flag)
{
	if ((byte >> flag) & 1)
		return (1);
	return (0);
}

int	ft_setbit(t_byte byte, int flag)
{
	return (byte | (1 << flag));
}

int	ft_delbit(t_byte byte, int flag)
{
	if (ft_hasbyte(byte, flag))
		return (byte ^ (1 << flag));
	return (byte);
}

int	ft_flipbits(t_byte byte, int flag)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (i < 32)
		res = res | (byte ^ (1 << i));
	return (res);
}
