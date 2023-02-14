/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:03:50 by corellan          #+#    #+#             */
/*   Updated: 2023/02/14 17:18:56 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_taking_fork_aux(t_phi **phi)
{
	gettimeofday(&((*phi)->tim), NULL);
	(*phi)->s1 = (*phi)->tim.tv_sec;
	(*phi)->us1 = (*phi)->tim.tv_usec;
	(*phi)->time = ((((*phi)->s1 - (*phi)->ti->s0) * 1000) + \
		(((*phi)->us1 - (*phi)->ti->us0) / 1000));
	printf("%ldms %d is taking a fork.\n", (*phi)->time, (*phi)->phi_num);
	(*phi)->f_state = 1;
	if ((*phi)->ti->philo_1 == 0)
	{
		printf("%ldms %d is taking a fork.\n", (*phi)->time, (*phi)->phi_num);
		if (((*phi)->phi_num == (*phi)->ti->n_philo) && \
			((*phi)->ti->n_philo > 1))
			(*phi)->ti->begin->f_state == 1;
		else if (((*phi)->phi_num < (*phi)->ti->n_philo))
			(*phi)->left->f_state == 1;
	}
}

void	ft_taking_fork(t_phi **phi)
{
	if ((*phi)->f_state == 1)
	{
		pthread_mutex_lock(&((*phi)->mutex));
		(*phi)->f_state = 0;
	}
	if (((*phi)->phi_num == (*phi)->ti->n_philo) && \
		((*phi)->ti->begin->f_state == 1) && ((*phi)->ti->n_philo > 1))
	{
		pthread_mutex_lock(&((*phi)->ti->begin->mutex));
		(*phi)->ti->begin->f_state = 0;
	}
	else if (((*phi)->ti->n_philo == 1))
		(*phi)->ti->philo_1 == 1;
	else if (((*phi)->phi_num < (*phi)->ti->n_philo) && \
		((*phi)->left->f_state == 1))
	{
		pthread_mutex_lock(&((*phi)->left->mutex));
		(*phi)->left->f_state = 0;
	}
	ft_taking_fork_aux(&(*phi));
}

void	ft_eating(t_phi **phi)
{
	printf("%ldms %d is eating.\n", (*phi)->time, (*phi)->phi_num);
	usleep((((*phi)->ti->t_eat) * 1000));
	(*phi)->o_time = (*phi)->time;
	gettimeofday(&((*phi)->tim), NULL);
	(*phi)->s1 = (*phi)->tim.tv_sec;
	(*phi)->us1 = (*phi)->tim.tv_usec;
	(*phi)->time = ((((*phi)->s1 - (*phi)->ti->s0) * 1000) + \
		(((*phi)->us1 - (*phi)->ti->us0) / 1000));
	if ((((*phi)->time) - ((*phi)->o_time)) > (*phi)->ti->t_die)
	{
		printf("%ldms %d died.\n", (*phi)->time, (*phi)->phi_num);
		pthread_mutex_lock(&((*phi)->ti->mutex_d));
		(*phi)->ti->die_st = 1;
		pthread_mutex_unlock(&((*phi)->ti->mutex_d));
		return ;
	}
}

void	ft_sleeping(t_phi **phi)
{
	gettimeofday(&((*phi)->tim), NULL);
	(*phi)->s1 = (*phi)->tim.tv_sec;
	(*phi)->us1 = (*phi)->tim.tv_usec;
	(*phi)->time = ((((*phi)->s1 - (*phi)->ti->s0) * 1000) + \
		(((*phi)->us1 - (*phi)->ti->us0) / 1000));
	if ((((*phi)->time) + (((*phi)->ti->t_sleep))) > (*phi)->ti->t_die)
	{
		printf("%ldms %d died.\n", (*phi)->time, (*phi)->phi_num);
		pthread_mutex_lock(&((*phi)->ti->mutex_d));
		(*phi)->ti->die_st = 1;
		pthread_mutex_unlock(&((*phi)->ti->mutex_d));
		return ;
	}
	printf("%ldms %d is sleeping.\n", (*phi)->time, (*phi)->phi_num);
	usleep((((*phi)->ti->t_sleep) * 1000));
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
