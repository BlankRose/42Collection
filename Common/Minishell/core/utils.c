/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:34:55 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/20 21:50:01 by flcollar         ###   ########.fr       */
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

t_plist	*ms_envptolist(char **envp)
{
	t_plist	*list;
	t_plist	*elem;
	char	**tmp;
	int		i;
	int		len;

	len = ms_arraylen(envp);
	i = 0;
	tmp = ft_split(envp[i], '=');
	list = ms_lstnew(tmp[0], tmp[1]);
	while (envp[++i])
	{
		tmp = ft_split(envp[i], '=');
		elem = ms_lstnew(tmp[0], tmp[1]);
		ms_lstadd_back(&list, elem);
	}
	return (list);
}

int	ms_isquote(int c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	ms_isoperator(int c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}
