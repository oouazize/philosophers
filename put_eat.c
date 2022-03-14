/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:14:31 by oouazize          #+#    #+#             */
/*   Updated: 2022/03/13 17:01:11 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_eat(t_philos	**private)
{
	(*private)->last_meal = get_time(*private);
	printf("%ld philo %d is eating\n", get_time(*private),
		(*private)->index + 1);
	(*private)->flag = 1;
	(*private)->bag->nb_eat++;
}
