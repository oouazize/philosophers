/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:17:16 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/28 20:01:13 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_sleep(t_philos	**private)
{
	printf("%ld philo %d is sleeping\n", get_time(*private),
		(*private)->index + 1);
	my_usleep(*private, (*private)->bag->time_sleep);
}
