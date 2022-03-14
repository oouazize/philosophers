/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:45:32 by oouazize          #+#    #+#             */
/*   Updated: 2022/03/01 12:39:14 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	non_numeric(const char *str, int j)
{
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (1);
		j++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;

	res = 0;
	i = ft_isspace(str);
	if (i)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	if (!str[i])
		return (0);
	if (non_numeric(str, i))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res > 2147483647 || res < -2147483648)
			return (0);
	}
	return (res);
}
