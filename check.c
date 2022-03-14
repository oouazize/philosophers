/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:35:52 by oouazize          #+#    #+#             */
/*   Updated: 2022/03/13 17:12:24 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check2(t_philos **private, t_philo **public, int *x)
{
	int	i;

	i = -1;
	while (++i < (*public)->num)
	{
		pthread_mutex_lock(&(*private)->bag->msg);
		if (get_time(&(*private)[i]) - (*private)[i].last_meal
			>= (*private)[i].bag->time_die && (*private)[i].flag == 0)
		{
			printf("%ld philo %d died\n", get_time(&(*private)[i]),
				(*private)[i].index + 1);
			*x = 0;
			break ;
		}
		if ((*private)[i].bag->arc == 6)
		{
			if ((*private)[i].bag->nb_eat >= (*private)[i].bag->num *
				(*private)[i].bag->must_eat)
			{
				*x = 0;
				break ;
			}
		}
		pthread_mutex_unlock(&(*private)->bag->msg);
	}
}

void	check(t_philos **private, t_philo **public)
{
	int	x;

	x = 1;
	while (x)
		check2(private, public, &x);
	(*public)->died = 0;
}
