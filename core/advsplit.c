/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:19:07 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/16 14:03:25 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static size_t	ms_splitadv_size(const char *s, char c)
{
	int		hasquote;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	hasquote = 0;
	while (s[i++])
	{
		while (s[i] && (hasquote || s[i] != c))
			hasquote = ms_checkquote(s[i++], hasquote);
		len++;
		while (s[i] == c && s[i])
			i++;
	}
	return (len);
}

static char	**ms_splitadv2(const char *s, char c, char **res)
{
	int		hasquote;
	size_t	len;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	hasquote = 0;
	while (s[y])
	{
		len = 0;
		while ((s[y] != c || hasquote) && s[y] && ++y)
		{
			hasquote = ms_checkquote(s[y - 1], hasquote);
			len++;
		}
		res[i] = malloc(len + 1);
		if (!res[i])
			return ((char **) ft_free_array((void **) res, i));
		ft_strlcpy(res[i++], &s[y - len], len + 1);
		while (s[y] == c && s[y])
			y++;
	}
	res[i] = 0;
	return (res);
}

char	**ms_splitadv(const char *s, char c)
{
	size_t	i;
	char	**r;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	r = (char **)malloc(sizeof(char *) * (ms_splitadv_size(&s[i], c) + 1));
	if (!r)
		return (0);
	return (ms_splitadv2(&s[i], c, r));
}

int	ms_checkquote(char c, int hasquote)
{
	if (!hasquote && c == '\'')
		hasquote = 1;
	else if (!hasquote && c == '\"')
		hasquote = 2;
	else if ((hasquote == 1 && c == '\'')
		|| (hasquote == 2 && c == '\"'))
		hasquote = 0;
	return (hasquote);
}
