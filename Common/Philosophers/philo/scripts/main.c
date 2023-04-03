/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:01:02 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 10:32:21 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int c, char **args)
{
	t_param			*param;

	param = ph_param_init(c, &args[1]);
	if (!param)
		return (1);
	if (param->time_sleep > param->time_death || param->amount == 1
		|| (param->amount % 2 && param->time_eat * 2 > param->time_death))
		ph_log(0, 0, 0);
	if (param->amount > 200)
		ph_error(3, 0);
	else if (ph_mutex_init(param))
	{
		if (param->amount > 1000)
			ph_log(1, 0, 0);
		ph_run(param);
	}
	free(param->philos);
	free(param);
	return (0);
}

// CHECK VALUES
/*printf("Number of Philos: %ld\nEating Time: %ldms\nSleeping Time: %ldms\n\
Time before Death: %ldms\nEating Requierements: %ld\nStart TimeStamp: %lds %dms \
\n", param->philos, param->time_eat, param->time_sleep, param->time_death, \
param->eat_requierd, param->start.tv_sec, param->start.tv_usec);*/