/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:03:50 by corellan          #+#    #+#             */
/*   Updated: 2023/02/13 16:51:33 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_taking_fork(t_phi **phi)
{
	if ((*phi)->f_state == 1)
	{
		pthread_mutex_lock(&((*phi)->mutex));
		(*phi)->f_state = 0;
		pthread_mutex_unlock(&((*phi)->mutex));
	}
}

void	ft_eating(t_phi **phi)
{
	gettimeofday(&((*phi)->tim), NULL);
	(*phi)->s1 = (*phi)->tim.tv_sec;
	(*phi)->us1 = (*phi)->tim.tv_usec;
	(*phi)->time = ((((*phi)->s1 - (*phi)->ti->s0) * 1000) + \
		(((*phi)->us1 - (*phi)->ti->us0) / 1000));
	usleep((((*phi)->ti->t_eat) * 1000));
	if ((((*phi)->time) + (((*phi)->ti->t_eat) * 1000)) > (*phi)->ti->t_die)
	{
		printf("%ldms %d died.\n", (*phi)->time, (*phi)->phi_num);
		pthread_mutex_lock(&((*phi)->ti->mutex_d));
		(*phi)->ti->die_st = 1;
		pthread_mutex_unlock(&((*phi)->ti->mutex_d));
		return ;
	}
	printf("%ldms %d is eating.\n", (*phi)->time, (*phi)->phi_num);
}

void	ft_sleeping(t_phi **phi)
{
	gettimeofday(&((*phi)->tim), NULL);
	(*phi)->s1 = (*phi)->tim.tv_sec;
	(*phi)->us1 = (*phi)->tim.tv_usec;
	(*phi)->time = ((((*phi)->s1 - (*phi)->ti->s0) * 1000) + \
		(((*phi)->us1 - (*phi)->ti->us0) / 1000));
	usleep((((*phi)->ti->t_sleep) * 1000));
	if ((((*phi)->time) + (((*phi)->ti->t_sleep) * 1000)) > (*phi)->ti->t_die)
	{
		printf("%ldms %d died.\n", (*phi)->time, (*phi)->phi_num);
		pthread_mutex_lock(&((*phi)->ti->mutex_d));
		(*phi)->ti->die_st = 1;
		pthread_mutex_unlock(&((*phi)->ti->mutex_d));
		return ;
	}
	printf("%ldms %d is sleeping.\n", (*phi)->time, (*phi)->phi_num);
}

void	ft_thinking(t_phi **phi)
{
	gettimeofday(&((*phi)->tim), NULL);
	(*phi)->s1 = (*phi)->tim.tv_sec;
	(*phi)->us1 = (*phi)->tim.tv_usec;
	(*phi)->time = ((((*phi)->s1 - (*phi)->ti->s0) * 1000) + \
		(((*phi)->us1 - (*phi)->ti->us0) / 1000));
	printf("%ldms %d is thinking.\n", (*phi)->time, (*phi)->phi_num);
}
