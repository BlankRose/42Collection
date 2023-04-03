/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:08:02 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 21:40:55 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	i = malloc(count * size);
	if (!i)
		return (0);
	ft_bzero(i, count * size);
	return (i);
}

void	*ft_realloc(void *prev, size_t n)
{
	void	*new;

	n += ft_memlen(prev);
	new = ft_calloc(n, sizeof(t_byte));
	if (!prev || !new)
		return (new);
	ft_memcpy(new, prev, n);
	free(prev);
	return (new);
}

void	*ft_memdup(void *mem)
{
	void	*new;

	new = ft_calloc(ft_memlen(mem), sizeof(t_byte));
	if (!new)
		return (0);
	return (ft_memcpy(new, mem, ft_memlen(mem)));
}

char	*ft_strexpend(char *prev, char *tmp, t_bool isfree)
{
	if (!prev && !tmp)
		return (0);
	prev = ft_realloc(prev, (ft_strlen(tmp) + 1) * sizeof(char));
	if (!prev)
		return (0);
	if (tmp)
	{
		ft_strlcat(prev, tmp, ft_strlen(prev) + ft_strlen(tmp) + 1);
		if (isfree)
			free(tmp);
	}
	return (prev);
}
