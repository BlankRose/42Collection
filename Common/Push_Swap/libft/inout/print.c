/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:34:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 11:57:05 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(int fd, const char *s, ...)
{
	t_vector3	v;
	va_list		args;
	char		*tmp;

	if (!s)
		return (-1);
	v = ft_vector3_new(0, 0, 0);
	va_start(args, s);
	tmp = 0;
	while (s[v.x])
	{
		v.y = ft_strlenlimit(&s[v.x], '%');
		v.z += ft_putnstr_fd(&s[v.x], fd, (size_t) v.y);
		v.x += v.y;
		if (ft_strchr(&s[v.x], '%'))
		{
			tmp = ft_convert(&s[++v.x], &args);
			v.z += ft_putstr_fd(tmp, fd);
			if (tmp)
				free(tmp);
			v.x++;
		}
	}
	va_end(args);
	return (v.z);
}

int	ft_printlst(int fd, const t_list *lst, const char *sep)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i += ft_putstr_fd((char *) lst->content, fd);
		lst = lst->next;
		if (lst)
			i += ft_putstr_fd((char *) sep, fd);
	}
	return (i);
}
