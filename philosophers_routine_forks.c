/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine_forks.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:47:23 by corellan          #+#    #+#             */
/*   Updated: 2023/02/20 15:42:12 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_taking_fork_print(t_phi **phi)
{
	printf("%ld %d is taking a fork\n", (*phi)->time, (*phi)->phi_num);
	if ((*phi)->ti->philo_1 == 0)
		printf("%ld %d is taking a fork\n", (*phi)->time, (*phi)->phi_num);
	else
	{
		ft_get_current_time(&(*phi));
		while (((*phi)->time - (*phi)->o_time) < (*phi)->ti->t_die)
			ft_get_current_time(&(*phi));
		(*phi)->d_state = 1;
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
		(*phi)->d_state = 1;
		ft_dying_state(&(*phi));
		ft_unlock_mutexes(&(*phi));
		return ;
	}
}

void	ft_taking_fork(t_phi **phi)
{
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
	if ((*phi)->d_state ==1)
		return ;
	else
		ft_taking_fork_print(&(*phi));
}
