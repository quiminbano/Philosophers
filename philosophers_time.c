/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:43:59 by corellan          #+#    #+#             */
/*   Updated: 2023/02/21 14:54:17 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_get_current_time_small(t_phi **phi)
{
	gettimeofday(&((*phi)->tim), NULL);
	(*phi)->s1 = (*phi)->tim.tv_sec;
	(*phi)->us1 = (*phi)->tim.tv_usec;
	(*phi)->time = ((((*phi)->s1 - (*phi)->ti->s0) * 1000) + \
		(((*phi)->us1 - (*phi)->ti->us0) / 1000));
}

void	ft_wait_threads(t_phi **phi)
{
	static int	i = 0;

	while ((*phi)->flag_loop == 0)
	{
		pthread_mutex_lock(&((*phi)->ti->mutex_s));
		if ((*phi)->flag == 0)
		{
			i++;
			(*phi)->flag = 1;
		}
		if (i == (*phi)->ti->n_philo)
			(*phi)->flag_loop = 1;
		pthread_mutex_unlock(&((*phi)->ti->mutex_s));
	}
	pthread_mutex_lock(&((*phi)->ti->mutex_time));
	if ((*phi)->ti->i == 0)
	{
		gettimeofday(&((*phi)->ti->tp), NULL);
		(*phi)->ti->s0 = (*phi)->ti->tp.tv_sec;
		(*phi)->ti->us0 = (*phi)->ti->tp.tv_usec;
		(*phi)->ti->i = 1;
	}
	pthread_mutex_unlock(&((*phi)->ti->mutex_time));
}

void	ft_get_current_time(t_phi **phi)
{
	usleep(500);
	gettimeofday(&((*phi)->tim), NULL);
	(*phi)->s1 = (*phi)->tim.tv_sec;
	(*phi)->us1 = (*phi)->tim.tv_usec;
	(*phi)->time = ((((*phi)->s1 - (*phi)->ti->s0) * 1000) + \
		(((*phi)->us1 - (*phi)->ti->us0) / 1000));
}
