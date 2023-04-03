/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:03:18 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/11 10:40:56 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_putnstr_fd(const char *s, int fd, size_t n)
{
	write(fd, s, n);
	return (n);
}

size_t	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

size_t	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

size_t	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
	return (ft_strlen(s));
}

size_t	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	size_t			y;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	nb = n;
	c = (nb % 10) + '0';
	y = 0;
	if (nb > 9)
		y = ft_putnbr_fd(nb / 10, fd);
	write(fd, &c, 1);
	return (y + 1);
}
