/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:48:49 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/16 23:39:55 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

char	*ms_charjoin(char *str, char c)
{
	char	*res;
	int		i;

	res = malloc(sizeof(*res) * ft_strlen(str) + 2);
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = c;
	res[++i] = '\0';
	//free(str);
	return (res);
}

char	**ms_appendtoarr(char **arr, char *str)
{
	char	**tmp;
	int		i;
	int		len;

	len = ms_arraylen(arr);
	tmp = malloc(sizeof(*tmp) * len + 2);
	i = -1;
	while (arr[++i])
		tmp[i] = arr[i];
	tmp[i++] = str;
	tmp[i] = NULL;
	free(arr);
	return (tmp);
}

char	*ms_getfromenvp(char *str)
{
	t_plist	*lst;
	char	*tmp;
	char	*res;
	int		i;

	tmp = malloc(sizeof(*tmp));
	res = malloc(sizeof(*tmp));
	if (!tmp || !res)
		return (NULL);
	tmp[0] = '\0';
	res[0] = '\0';
	lst = g_main -> envplist;
	i = -1;
	// while (str[++i] && !ft_isset(str[i], "\"\'$") && !ft_isspace(str[i]))
	while (str[++i] && str[i] != '\"' && !ft_isspace(str[i]))
		tmp = ms_charjoin(tmp, str[i]);
	while (lst)
	{
		if (ft_strlen(tmp) == ft_strlen(lst -> key)
			&& !ft_strncmp(tmp, lst -> key, ft_strlen(tmp)))
		{
			res = ft_strjoin(res, lst -> value);
			break ;
		}
		lst = lst -> next;
	}
	return (res);
}
