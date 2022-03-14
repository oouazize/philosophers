/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:26:14 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/28 20:28:03 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create(t_philo **public, t_philos **private, pthread_t arr[])
{
	int	i;

	i = -1;
	while (++i < (*public)->num)
	{
		(*private)[i].index = i;
		(*private)[i].bag = *public;
		(*private)->last_meal = get_time(*private);
		if (pthread_create(&arr[i], NULL, &routine, &(*private)[i]))
			return (1);
		usleep(100);
	}
	return (0);
}
