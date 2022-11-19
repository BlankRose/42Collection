/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:34:03 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/25 14:54:55 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_convert_uint(const char *src, unsigned int arg)
{
	char	*str;

	str = 0;
	if (src[0] == 'u')
		str = ft_itoa_unsigned(arg);
	else if (src[0] == 'x')
		str = ft_dec2base(arg, HEXA_LOW);
	else if (src[0] == 'X')
		str = ft_dec2base(arg, HEXA_UP);
	else if (src[0] == 'o')
		str = ft_dec2base(arg, OCTAL);
	else if (src[0] == 'b')
		str = ft_dec2base(arg, BINARY);
	return (str);
}

static int	ft_convert(const char *src, va_list *args, int fd)
{
	char	*str;
	int		y;

	str = 0;
	if (src[0] == '%')
		return (ft_putchar_fd('%', fd));
	else if (src[0] == 'c')
		return (ft_putchar_fd(va_arg(*args, int), fd));
	else if (src[0] == 's')
		return (ft_putstr_fd(va_arg(*args, char *), fd));
	else if (src[0] == 'd' || src[0] == 'i')
		str = ft_itoa(va_arg(*args, int));
	else if (src[0] == 'p')
		str = ft_getaddress(va_arg(*args, void *));
	if (ft_isset(src[0], "uxXob"))
		str = ft_convert_uint(src, va_arg(*args, unsigned int));
	if (!str)
		return (-1);
	y = ft_putstr_fd(str, fd);
	free(str);
	return (y);
}

int	ft_printf(int fd, const char *s, ...)
{
	t_vector3	v;
	va_list		args;

	if (!s)
		return (-1);
	v = ft_vector3_new(0, 0, 0);
	va_start(args, s);
	while (s[v.x])
	{
		v.y = ft_strlenlimit(&s[v.x], '%');
		v.z += ft_putnstr_fd(&s[v.x], fd, (size_t) v.y);
		v.x += v.y;
		if (ft_strchr(&s[v.x], '%'))
		{
			v.z += ft_convert(&s[++v.x], &args, fd);
			v.x++;
		}
	}
	va_end(args);
	return (v.z);
}

int	ft_printlst(int fd, const t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i += ft_putstr_fd((char *) lst->content, fd);
		lst = lst->next;
	}
	return (i);
}
