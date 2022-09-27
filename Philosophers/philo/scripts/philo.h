/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:52:00 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 11:17:10 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*********************************************************/
/*                                                       */
/*                INCLUDES AND DEFINES                   */
/* A few C standard library includes allowed and defines */
/*                                                       */
/*********************************************************/

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define STATE_EAT 1
# define STATE_SLEEP 2
# define STATE_THONK 3
# define STATE_DEAD 4

# define ACTION_FORK 4
# define ACTION_SLEEP 5
# define ACTION_EAT 6
# define ACTION_THONK 7
# define ACTION_DEAD 8
# define ACTION_GOAL 9

/*********************************************************/
/*                                                       */
/*                      STRUCTURES                       */
/*    Various structures for easier variable handling    */
/*                                                       */
/*********************************************************/

typedef unsigned long			t_ulong;
typedef struct s_parameters		t_param;

/* Contains every data about a philosopher */
typedef struct s_philosopher {
	struct timeval		last_eat;
	pthread_t			thread;
	t_param				*param;
	id_t				id;
	size_t				eat;
	size_t				lfork;
	size_t				rfork;
	int					iseating;
}	t_philo;

/* Contains every parameters about the simulation */
typedef struct s_parameters {
	pthread_mutex_t		writting;
	pthread_mutex_t		*forks;
	struct timeval		start;
	t_ulong				time_eat;
	t_ulong				time_sleep;
	t_ulong				time_death;
	t_ulong				eat_requierd;
	t_ulong				amount;
	t_philo				*philos;
	int					running;
}	t_param;

/*********************************************************/
/*                                                       */
/*                  UTILITIES FUNCTIONS                  */
/*  Functions taken back from LIBFT used by the program  */
/*                                                       */
/*********************************************************/

/* Converts the string STR into its representative UNSIGNED LONG counterpart
Return: found value */
t_ulong		ft_atoi(const char *str);

/* Check the length of the string S
Return: length of S */
size_t		ft_strlen(const char *s);

/* Calculates the time that has been elapsed since LAST time
Return: time difference
REQUIERD: gettimeofday() !*/
t_ulong		ft_elapsed(const struct timeval last);

/* Calculates the time that has been elapsed since SEC (s) : USEC (ms)
Return: time difference
REQUIERD: gettimeofday() !*/
t_ulong		ft_elapsed_time(t_ulong sec, t_ulong usec);

/*********************************************************/
/*                                                       */
/*                   PROGRAMM FUNCTIONS                  */
/*    Specifics functions to run properly the program    */
/*                                                       */
/*********************************************************/

/* It will starts a new simulation by using the given PARAMETERs */
void		ph_run(t_param *param);

/* Function used by Threads for handling Philosophers using DATA */
void		*ph_philo_thread(void *data);

/* Initialize PHILO using PARAM and I as its index */
void		ph_philo_init(t_philo *philo, t_param *param, int i);

/* Create a new PARAM structure using C and ARGS to define its values
Return: newly created PARAM structure */
t_param		*ph_param_init(int c, char **args);

/* Initialize mutexes within PARAM
Return: 1 (SUCCESS) or 0 (FAIL) */
int			ph_mutex_init(t_param *param);

/* Displays a log message depending on the LOG reference */
void		ph_log(int log, t_ulong time, id_t id);

/* Displays an error message depending on the ERR reference and free DATA
Return: 0 (NULL) */
void		*ph_error(int err, void *data);

#endif