/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:07:48 by cciobanu          #+#    #+#             */
/*   Updated: 2022/04/22 17:09:11 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;

	result = malloc(sizeof(*s) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			result[i] = s[start + i];
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}

int	ft_wordcount(const char *str, char c)
{
	int	res;
	int	issep;

	res = 0;
	issep = 1;
	while (*str)
	{
		if (*str != c && issep == 1)
		{
			issep = 0;
			res++;
		}
		else if (*str == c)
			issep = 1;
		str++;
	}
	return (res);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**res;

	res = malloc((sizeof(char *) * (ft_wordcount(str, c) + 1)));
	if (!str || !res)
		return (0);
	i = 0;
	j = 0;
	k = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && k < 0)
			k = i;
		else if ((str[i] == c || i == ft_strlen(str)) && k >= 0)
		{
			res[j++] = ft_substr(str, k, i - k);
			k = -1;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lengths1;
	int		lengths2;
	int		i;
	int		j;
	char	*result;

	i = 0;
	lengths1 = ft_strlen(s1);
	lengths2 = ft_strlen(s2);
	result = malloc(sizeof(*s1) * (lengths1 + lengths2) + 1);
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j])
	{
		result[i] = s2[j];
		i++;
	}
	result[i] = '\0';
	return (result);
}
