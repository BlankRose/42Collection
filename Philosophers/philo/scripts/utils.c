/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:29:18 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 11:01:39 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

t_ulong	ft_atoi(const char *str)
{
	t_ulong		res;
	size_t		i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '-'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ' || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res);
}

t_ulong	ft_elapsed(const struct timeval last)
{
	struct timeval	now;
	long			usec;
	long			sec;

	gettimeofday(&now, 0);
	sec = now.tv_sec - last.tv_sec;
	usec = now.tv_usec - last.tv_usec;
	return ((t_ulong)((sec * 1000) + (usec / 1000)));
}

/*t_ulong	ft_elapsed_time(t_ulong sec, t_ulong usec)
{
	struct timeval	now;
	long			t_usec;
	long			t_sec;

	if (usec > 1000000)
	{
		sec = usec / 1000000;
		usec = usec % 1000000;
	}
	gettimeofday(&now, 0);
	t_sec = now.tv_sec - sec;
	t_usec = now.tv_usec - usec;
	return ((t_ulong)((sec * 1000000) + usec));
}*/