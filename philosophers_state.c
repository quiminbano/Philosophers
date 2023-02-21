/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:38:22 by corellan          #+#    #+#             */
/*   Updated: 2023/02/21 14:53:06 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_dying_state(t_phi **phi)
{
	pthread_mutex_lock(&((*phi)->ti->mutex_dead));
	if ((*phi)->ti->die_st == 0 && (*phi)->d_state == 1)
	{
		printf("%ld %d died\n", (*phi)->time, (*phi)->phi_num);
		(*phi)->ti->die_st = 1;
	}
	if ((*phi)->ti->die_st == 1 && (*phi)->d_state == 0)
	{
		(*phi)->d_state = 1;
		ft_unlock(&(*phi));
	}
	pthread_mutex_unlock(&((*phi)->ti->mutex_dead));
}

void	ft_eating_state(t_phi **phi)
{
	pthread_mutex_lock(&((*phi)->ti->mutex_eat));
	if (((*phi)->count_eat >= (*phi)->ti->ti_eat) && ((*phi)->eat_s == 0) && \
		((*phi)->ti->philo_eat_c < (*phi)->ti->n_philo))
	{
		((*phi)->ti->philo_eat_c)++;
		(*phi)->eat_s = 1;
	}
	if ((*phi)->ti->philo_eat_c >= (*phi)->ti->n_philo)
		(*phi)->e_counter = (*phi)->ti->philo_eat_c;
	pthread_mutex_unlock(&((*phi)->ti->mutex_eat));
}
