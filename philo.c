/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:28:21 by oouazize          #+#    #+#             */
/*   Updated: 2022/03/13 17:24:21 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int arc, char *arv[])
{
	t_philo		*public;
	t_philos	*private;
	pthread_t	*arr;
	int			i;

	i = -1;
	public = malloc(sizeof(t_philo));
	if (init(&public, &private, arc, arv))
		return (0);
	arr = malloc(sizeof(pthread_t) * ft_atoi(arv[1]));
	if (create(&public, &private, arr))
		return (0);
	check(&private, &public);
	while (++i < public->num)
		pthread_mutex_destroy(public->fork + i);
	pthread_mutex_destroy(&public->msg);
}
