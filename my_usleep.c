/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:18:55 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/28 19:52:51 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(t_philos *private, int wanted_time)
{
	long long	start_time;

	start_time = get_time(private);
	while (get_time(private) - start_time < wanted_time)
		usleep(200);
}
