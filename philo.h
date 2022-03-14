/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:29:51 by oouazize          #+#    #+#             */
/*   Updated: 2022/03/13 17:09:28 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philo
{
	int				num;
	int				time_eat;
	long			time_die;
	int				time_sleep;
	int				must_eat;
	int				arc;
	int				died;
	int				nb_eat;
	long			zerotime;
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg;
}				t_philo;

typedef struct philos
{
	int		index;
	int		flag;
	long	last_meal;
	t_philo	*bag;
}				t_philos;

int		ft_atoi(const char *str);
void	*routine(void *arg);
long	get_time(t_philos *private);
void	put_eat(t_philos **private);
void	put_sleep(t_philos **private);
void	my_usleep(t_philos *private, int i);
int		init(t_philo **pv, t_philos **private, int arc, char *arv[]);
void	check(t_philos **private, t_philo **pv);
int		create(t_philo **pv, t_philos **private, pthread_t arr[]);

#endif
