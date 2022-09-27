/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:30:11 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 11:54:30 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ph_wait(t_param *param, t_ulong time)
{
	struct timeval	start;

	if (time < 5000)
		usleep(time);
	gettimeofday(&start, 0);
	while (param->running)
	{
		if (ft_elapsed(start) >= time)
			break ;
		usleep(1000);
	}
}

static void	ph_send_msg(t_philo *philo, t_param *param, id_t state)
{
	pthread_mutex_lock(&param->writting);
	if (param->running)
		ph_log(state, ft_elapsed(param->start), philo->id + 1);
	pthread_mutex_unlock(&param->writting);
}

static void	ph_eat(t_philo *philo, t_param *param)
{
	pthread_mutex_lock(&param->forks[philo->lfork]);
	if (!param->running)
	{
		pthread_mutex_unlock(&param->forks[philo->lfork]);
		return ;
	}
	ph_send_msg(philo, param, ACTION_FORK);
	pthread_mutex_lock(&param->forks[philo->rfork]);
	if (!param->running)
	{
		pthread_mutex_unlock(&param->forks[philo->lfork]);
		pthread_mutex_unlock(&param->forks[philo->rfork]);
		return ;
	}
	philo->iseating = 1;
	ph_send_msg(philo, param, ACTION_FORK);
	ph_send_msg(philo, param, ACTION_EAT);
	ph_wait(param, param->time_eat);
	philo->eat++;
	gettimeofday(&philo->last_eat, 0);
	pthread_mutex_unlock(&param->forks[philo->lfork]);
	pthread_mutex_unlock(&param->forks[philo->rfork]);
	philo->iseating = 0;
}

void	*ph_philo_thread(void *data)
{
	t_philo			*philo;
	t_param			*param;

	philo = (t_philo *) data;
	param = philo->param;
	ph_send_msg(philo, param, ACTION_THONK);
	if (param->amount < 2)
	{
		usleep(param->time_death + 50);
		return (0);
	}
	if (philo->id % 2)
		ph_wait(param, param->time_eat);
	while (param->running)
	{
		ph_eat(philo, param);
		if (!param->running)
			break ;
		ph_send_msg(philo, param, ACTION_SLEEP);
		ph_wait(param, param->time_sleep);
		if (!param->running)
			break ;
		ph_send_msg(philo, param, ACTION_THONK);
	}
	return (0);
}
