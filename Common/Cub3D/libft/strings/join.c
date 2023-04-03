/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:31:15 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 21:36:24 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*r;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	r = (char *) malloc((len + 1) * sizeof(char));
	if (!r)
		return (0);
	ft_strlcpy(r, s1, len + 1);
	ft_strlcat(r, s2, len + 1);
	return (r);
}

char	*ft_strjoin_multi(const char *base, ...)
{
	va_list		args;
	char		*tmp;
	char		*res;

	if (!base)
		return (0);
	res = ft_strdup(base);
	if (!res)
		return (0);
	va_start(args, base);
	tmp = va_arg(args, char *);
	while (tmp)
	{
		res = ft_strexpend(res, tmp, FALSE);
		if (!res)
			break ;
		tmp = va_arg(args, char *);
	}
	va_end(args);
	return (res);
}
