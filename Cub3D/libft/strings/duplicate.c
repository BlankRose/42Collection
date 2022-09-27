/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:59:55 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 17:31:11 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;

	r = (char *) malloc((ft_max(ft_strlen(s), len + 1)) * sizeof(char));
	if (!r)
		return (0);
	if (start < ft_strlen(s))
		ft_strlcpy(r, &s[start], len + 1);
	else
		r[0] = '\0';
	return (r);
}

char	*ft_chrdup(const char c)
{
	char	*r;

	r = (char *) ft_calloc(2, sizeof(char));
	if (!r)
		return (0);
	r[0] = c;
	return (r);
}

char	*ft_strdup(const char *s1)
{
	char	*r;

	if (!s1)
		return (0);
	r = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!r)
		return (0);
	ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	return (r);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*r;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	len = ft_strlen(s1);
	while (len > 0 && ft_isset(s1[len - 1], set))
		len--;
	r = malloc((ft_min(0, len - i) + 1) * sizeof(char));
	if (!r)
		return (NULL);
	ft_strlcpy(r, &s1[i], (len - i) + 1);
	return (r);
}
