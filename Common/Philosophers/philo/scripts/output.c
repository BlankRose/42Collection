/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:38:19 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 11:21:14 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_log(int log, t_ulong time, id_t id)
{
	if (log == 0)
		printf("\033[33;1mWarning: Short Lifespan\n\033[0;2;33mThe simulation is \
likely to die almost instantly because of given arguments!\n\033[0m");
	else if (log == 2)
		printf("\033[32;1m > SIMULATION START\n\033[0m");
	else if (log == 3)
		printf("\033[31;1m > SIMULATION END\n\033[0m");
	else if (log == 4)
		printf("%ldms - %d has taken a fork.\n", time, id);
	else if (log == 5)
		printf("%ldms - %d is now sleeping.\n", time, id);
	else if (log == 6)
		printf("%ldms - %d is now eating.\n", time, id);
	else if (log == 7)
		printf("%ldms - %d is now thinking.\n", time, id);
	else if (log == 8)
		printf("\033[31m%ldms - %d has died!\n\033[0m", time, id);
	else if (log == 9)
		printf("\033[31m%ldms - Every philosophers has eaten %d times!\n\033[0m", \
		time, id);
}

void	*ph_error(int err, void *data)
{
	printf("\033[31;1mError: ");
	if (err == 0)
		printf("Syntax\n\033[0;2;31m./philo <nb_philos> \
<time_death (ms)> <time_eat (ms)> <time_sleep (ms)> [times_philos_eat]");
	else if (err == 1)
		printf("Invalid Arguments\n\033[0;2;31mArguments couldn't be \
parsed into INTs or one is null or negative!");
	else if (err == 2)
		printf("Internal Issues\n\033[0;2;31mAn internal issues occured \
(failed to malloc() or failed to init mutex)!");
	else if (err == 3)
		printf("Threads Overflow Softlock\n\033[0;2;31mToo many Philosophers \
(> 200) might cause to go beyong threads limits and EVEN crash the system!");
	else
		printf("Unkown");
	printf("\n\033[0m");
	if (data)
		free(data);
	return (0);
}
