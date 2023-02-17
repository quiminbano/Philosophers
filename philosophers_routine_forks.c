/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine_forks.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:47:23 by corellan          #+#    #+#             */
/*   Updated: 2023/02/17 21:19:55 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_taking_fork_print(t_phi **phi)
{
	ft_get_current_time(&(*phi));
	printf("%ldms %d is taking a fork.\n", (*phi)->time, (*phi)->phi_num);
	if ((*phi)->ti->philo_1 == 0)
		printf("%ldms %d is taking a fork.\n", (*phi)->time, (*phi)->phi_num);
	else
	{
		(*phi)->o_time = (*phi)->time;
		while (((*phi)->time - (*phi)->o_time) < (*phi)->ti->t_die)
			ft_get_current_time(&(*phi));
		ft_dying_state(&(*phi));
		pthread_mutex_unlock(&((*phi)->mutex));
		return ;
	}
}

static void	ft_taking_fork_time(t_phi **phi)
{
	ft_get_current_time(&(*phi));
	if (((*phi)->time - (*phi)->o_time) >= (*phi)->ti->t_die)
	{
		ft_dying_state(&(*phi));
		ft_unlock_mutexes(&(*phi));
		return ;
	}
}

void	ft_taking_fork(t_phi **phi)
{
	(*phi)->o_time = (*phi)->time;
	pthread_mutex_lock(&((*phi)->mutex));
	if ((*phi)->f_state == 0)
		(*phi)->f_state = 1;
	if (((*phi)->ti->n_philo > 1) && ((*phi)->phi_num == (*phi)->ti->n_philo))
	{
		pthread_mutex_lock(&((*phi)->ti->begin->mutex));
		if ((*phi)->ti->begin->f_state == 0)
			(*phi)->ti->begin->f_state = 0;
	}
	else if (((*phi)->ti->n_philo) == 1)
		(*phi)->ti->philo_1 = 1;
	else if (((*phi)->phi_num < (*phi)->ti->n_philo))
	{
		pthread_mutex_lock(&((*phi)->left->mutex));
		if ((*phi)->left->f_state == 0)
			(*phi)->left->f_state = 1;
	}
	if ((*phi)->ti->philo_1 == 0)
		ft_taking_fork_time(&(*phi));
	if ((*phi)->ti->die_st ==1)
		return ;
	else
		ft_taking_fork_print(&(*phi));
}
