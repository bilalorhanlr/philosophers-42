/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_write_case3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:14:34 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:14:35 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	philo_write_case3(char *a, t_all *all, t_philo_features *philo)
{
	int	ad;
	int	as;

	ad = philo_write_utils(all);
	as = philo_write_utils2(all);
	if (as && !ad)
	{
		pthread_mutex_lock(&all->dead_control2);
		all->dead = 1;
		ad = 1;
		pthread_mutex_unlock(&all->dead_control2);
		printf("%lld %d %s \n", get_time(all), philo->position, "dead");
		return ;
	}
	if (!ad && all->all_eat != 1)
	{
		pthread_mutex_lock(&all->print);
		if (dead_and_eat_control(all))
		{
			printf("%lld %d %s \n", get_time(all), philo->position, a);
		}
		pthread_mutex_unlock(&all->print);
	}
	return ;
}
