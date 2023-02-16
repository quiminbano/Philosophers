/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:03:50 by corellan          #+#    #+#             */
/*   Updated: 2023/02/16 16:53:02 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_thinking(t_phi **phi)
{
	ft_get_current_time(&(*phi));
	printf("%ldms %d is thinking.\n", (*phi)->time, (*phi)->phi_num);
	if ((((*phi)->phi_num) % 2) == 0)
		usleep(3000);
}

void	ft_eating(t_phi **phi)
{
	printf("%ldms %d is eating.\n", (*phi)->time, (*phi)->phi_num);
	(*phi)->o_time = (*phi)->time;
	while (((*phi)->time - (*phi)->o_time) < (*phi)->ti->t_eat)
	{
		ft_get_current_time(&(*phi));
		if (((*phi)->time - (*phi)->o_time) >= (*phi)->ti->t_die)
		{
			pthread_mutex_lock(&((*phi)->ti->mutex_d));
			(*phi)->ti->die_st = 1;
			pthread_mutex_unlock(&((*phi)->ti->mutex_d));
			ft_unlock_mutexes(&(*phi));
			return ;
		}
		else if ((*phi)->ti->die_st == 1)
			return ;
	}
	ft_unlock_mutexes(&(*phi));
}

void	ft_sleeping(t_phi **phi)
{
	printf("%ldms %d is sleeping.\n", (*phi)->time, (*phi)->phi_num);
	while (((*phi)->time - (*phi)->o_time - (*phi)->ti->t_eat) < (*phi)->ti->t_sleep)
	{
		ft_get_current_time(&(*phi));
		if (((*phi)->time - (*phi)->o_time) >= (*phi)->ti->t_die)
		{
			printf("%ldms %d died.\n", (*phi)->time, (*phi)->phi_num);
			pthread_mutex_lock(&((*phi)->ti->mutex_d));
			(*phi)->ti->die_st = 1;
			pthread_mutex_unlock(&((*phi)->ti->mutex_d));
			return ;
		}
		else if ((*phi)->ti->die_st == 1)
			return ;
	}
	usleep(500);
}
