/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:49:50 by oouazize          #+#    #+#             */
/*   Updated: 2022/03/13 17:12:27 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock(t_philos *private, int i)
{
	int	mod;

	mod = (private->index + 1) % private->bag->num;
	if (i == 1)
	{
		pthread_mutex_lock(&private->bag->fork[private->index]);
		pthread_mutex_lock(&private->bag->msg);
		printf("%ld philo %d has taken a fork\n", get_time(private),
			private->index + 1);
		pthread_mutex_unlock(&private->bag->msg);
		pthread_mutex_lock(&private->bag->fork[mod]);
		pthread_mutex_lock(&private->bag->msg);
		printf("%ld philo %d has taken a fork\n", get_time(private),
			private->index + 1);
		pthread_mutex_unlock(&private->bag->msg);
	}
	else
	{
		pthread_mutex_lock(&private->bag->msg);
		pthread_mutex_unlock(&private->bag->fork[private->index]);
		pthread_mutex_unlock(&private->bag->fork[mod]);
		pthread_mutex_unlock(&private->bag->msg);
	}
}

void	*routine(void *arg)
{
	t_philos	*private;

	private = arg;
	private->last_meal = 0;
	private->flag = 0;
	private->bag->died = 1;
	private->bag->nb_eat = 0;
	while (private->bag->died)
	{
		lock(private, 1);
		put_eat(&private);
		my_usleep(private, private->bag->time_eat);
		private->flag = 0;
		lock(private, 0);
		put_sleep(&private);
		pthread_mutex_lock(&private->bag->msg);
		printf("%ld philo %d is thinking\n", get_time(private),
			private->index + 1);
		pthread_mutex_unlock(&private->bag->msg);
	}
	return (0);
}
