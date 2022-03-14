/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:59:26 by oouazize          #+#    #+#             */
/*   Updated: 2022/03/01 12:46:58 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	inatoi(t_philo **public, char *arv[])
{
	(*public)->num = ft_atoi(arv[1]);
	(*public)->time_die = ft_atoi(arv[2]);
	(*public)->time_eat = ft_atoi(arv[3]);
	(*public)->time_sleep = ft_atoi(arv[4]);
	if (arv[5])
		(*public)->must_eat = ft_atoi(arv[5]);
	if (!((*public)->num) || !(*public)->time_die
		|| !(*public)->time_eat || !(*public)->time_sleep
		|| !(*public)->must_eat)
		return (1);
	return (0);
}

int	init(t_philo **public, t_philos **private, int arc, char *arv[])
{
	struct timeval	t1;
	int				i;

	i = -1;
	gettimeofday(&t1, NULL);
	if (arc == 5 || arc == 6)
	{
		(*public)->must_eat = -1;
		if (inatoi(public, arv))
			return (1);
		(*public)->arc = arc;
		(*public)->zerotime = t1.tv_sec * 1000 + t1.tv_usec / 1000;
		(*public)->fork = malloc(sizeof(pthread_mutex_t) * (*public)->num);
		*private = (t_philos *)malloc(sizeof(t_philos) * (*public)->num);
		pthread_mutex_init(&(*public)->msg, NULL);
		while (++i < (*public)->num)
		{
			if (pthread_mutex_init(&(*public)->fork[i], NULL))
				return (1);
		}
	}
	else
		return (1);
	return (0);
}
