/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:24:38 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 11:51:53 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_verify_alive(t_param *param)
{
	t_ulong		i;

	i = 0;
	while (i < param->amount && param->running)
	{
		if (ft_elapsed(param->philos[i].last_eat) >= param->time_death
			&& !param->philos[i].iseating)
		{
			ph_log(ACTION_DEAD, ft_elapsed(param->start), i + 1);
			param->running = 0;
		}
		i++;
	}
}

static void	ph_verify_goal(t_param *param)
{
	size_t		least_eat;
	t_ulong		i;

	i = 0;
	least_eat = -1;
	while (i < param->amount && param->running)
	{
		if (least_eat < 0)
			least_eat = param->philos[i].eat;
		else if (least_eat > param->philos[i].eat)
			least_eat = param->philos[i].eat;
		i++;
	}
	if (least_eat >= param->eat_requierd)
		param->running = 0;
}

static void	ph_verify_runtime(t_param *param)
{
	while (param->running)
	{
		ph_verify_alive(param);
		if (param->eat_requierd)
			ph_verify_goal(param);
	}
}

void	ph_run(t_param *param)
{
	size_t		i;

	i = 0;
	ph_log(2, 0, 0);
	gettimeofday(&param->start, 0);
	param->running = 1;
	while (i < param->amount)
	{
		ph_philo_init(&param->philos[i], param, i);
		i++;
	}
	i = 0;
	ph_verify_runtime(param);
	while (i < param->amount)
		pthread_join(param->philos[i++].thread, NULL);
	i = 0;
	while (i < param->amount)
		pthread_mutex_destroy(&param->forks[i++]);
	pthread_mutex_destroy(&param->writting);
	ph_log(3, 0, 0);
}
