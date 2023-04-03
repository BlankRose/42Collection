/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:00:32 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 11:53:54 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_param	*ph_param_init(int c, char **args)
{
	t_param		*param;

	if (c < 5 || c > 6)
		return (ph_error(0, 0));
	param = malloc(sizeof(t_param));
	if (!param)
		return (ph_error(2, 0));
	param->amount = ft_atoi(args[0]);
	param->time_death = ft_atoi(args[1]);
	param->time_eat = ft_atoi(args[2]);
	param->time_sleep = ft_atoi(args[3]);
	param->eat_requierd = 0;
	if (c == 6)
		param->eat_requierd = ft_atoi(args[4]);
	if (!param->amount || !param->time_death || !param->time_eat
		|| !param->time_sleep || (!param->eat_requierd && c == 6))
		return (ph_error(1, param));
	param->philos = malloc(sizeof(t_philo) * param->amount);
	if (!param->philos)
		return (ph_error(2, param));
	return (param);
}

int	ph_mutex_init(t_param *param)
{
	t_ulong		i;

	i = 0;
	if (pthread_mutex_init(&param->writting, 0))
		return (0);
	param->forks = malloc(sizeof(pthread_mutex_t) * param->amount);
	if (!param->forks)
		return (0);
	while (i < param->amount)
	{
		if (pthread_mutex_init(&param->forks[i++], 0))
		{
			free (param->forks);
			return (0);
		}
	}
	return (1);
}

void	ph_philo_init(t_philo *philo, t_param *param, int i)
{
	philo->id = i;
	philo->lfork = i;
	philo->rfork = (i + 1) % param->amount;
	philo->param = param;
	philo->eat = 0;
	philo->iseating = 0;
	gettimeofday(&philo->last_eat, 0);
	pthread_create(&(param->philos[i].thread), 0, ph_philo_thread, \
		&param->philos[i]);
}
