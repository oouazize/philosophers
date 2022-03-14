/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:14:57 by oouazize          #+#    #+#             */
/*   Updated: 2022/03/03 12:12:50 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_philos *public)
{
	struct timeval	t0;

	gettimeofday(&t0, NULL);
	return (((t0.tv_sec * 1000) + (t0.tv_usec / 1000)) - public->bag->zerotime);
}
