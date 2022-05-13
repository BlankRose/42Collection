/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:34:55 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 16:06:37 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	ms_arraylen(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**ms_array_cpy(char **arr)
{
	char	**res;
	int		i;
	int		len;

	i = -1;
	len = ms_arraylen(arr);
	res = malloc(sizeof(*res) * len + 1);
	if (!res)
		return (NULL);
	while (++i < len)
		res[i] = ft_strdup(arr[i]);
	res[i] = NULL;
	return (res);
}

t_list	*ms_arrtolist(char **arr)
{
	ms_arraylen(arr);
	return (NULL);
}
