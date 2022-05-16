/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:06:10 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 00:07:39 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchrset(const char *s, char *set)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isset(s[i], set))
			return ((char *) &s[i]);
		i++;
	}
	if (ft_isset('\0', set))
		return ((char *) &s[i]);
	return (0);
}
