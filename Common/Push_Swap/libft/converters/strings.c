/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:07:59 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/06 21:24:01 by flcollar         ###   ########.fr       */
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

char	*ft_convert(const char *src, va_list *args)
{
	char	*str;

	str = 0;
	if (src[0] == '%')
		str = ft_chrdup('%');
	else if (src[0] == 'c')
		str = ft_chrdup(va_arg(*args, int));
	else if (src[0] == 's')
	{
		str = ft_strdup(va_arg(*args, char *));
		if (!str)
			str = ft_strdup("(null)");
	}
	else if (src[0] == 'd' || src[0] == 'i')
		str = ft_itoa(va_arg(*args, int));
	else if (src[0] == 'p')
		str = ft_getaddress(va_arg(*args, void *));
	if (ft_isset(src[0], "uxXob"))
		str = ft_convert_uint(src, va_arg(*args, unsigned int));
	return (str);
}

char	*ft_strconvert(const char *s, ...)
{
	t_vector3	v;
	va_list		args;
	char		*new;
	char		*tmp;

	va_start(args, s);
	v = ft_vector3_new(0, 0, 0);
	new = 0;
	while (s && s[v.x])
	{
		v.y = ft_strlenlimit(&s[v.x], '%');
		new = ft_strexpend(new, ft_substr(&s[v.x], 0, v.y), 0);
		v.x += v.y;
		if (ft_strchr(&s[v.x], '%'))
		{
			tmp = ft_convert(&s[++v.x], &args);
			if (tmp && tmp[0] == '%')
				new = ft_strexpend(new, tmp, 0);
			new = ft_strexpend(new, tmp, 1);
			v.x++;
		}
	}
	va_end(args);
	return (new);
}
