/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine_forks.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:47:23 by corellan          #+#    #+#             */
/*   Updated: 2023/02/24 12:51:13 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_taking_fork_print(t_phi **phi)
{
	printf("%ld %d has taken a fork\n", (*phi)->time, (*phi)->phi_num);
	if ((*phi)->ti->philo_1 == 0)
		printf("%ld %d has taken a fork\n", (*phi)->time, (*phi)->phi_num);
	else
	{
		ft_get_current_time_small(&(*phi));
		while (((*phi)->time - (*phi)->o_time) < (*phi)->ti->t_die)
			ft_get_current_time_small(&(*phi));
		(*phi)->d_state = 1;
		ft_dying_state(&(*phi));
		pthread_mutex_unlock(&((*phi)->mutex));
		return ;
	}
}

static void	ft_taking_fork_time(t_phi **phi)
{
	ft_get_current_time_small(&(*phi));
	if (((*phi)->time - (*phi)->o_time) >= (*phi)->ti->t_die)
	{
		(*phi)->d_state = 1;
		ft_dying_state(&(*phi));
		ft_unlock_mutexes(&(*phi));
		return ;
	}
}

static int	ft_am_i_dead(t_phi **phi)
{
	if (((((*phi)->ti->t_die) - \
		(((*phi)->time - (*phi)->o_time) - (*phi)->ti->t_sleep)) < \
		(((*phi)->ti->t_eat) - 5)) && ((*phi)->cycle == 2) && \
		((*phi)->ti->n_philo % 2 == 0))
	{
		while (((*phi)->time - (*phi)->o_time) < ((*phi)->ti->t_die))
			ft_get_current_time(&(*phi));
	}
	else if (((((*phi)->ti->t_die) - \
		(((*phi)->time - (*phi)->o_time) - (*phi)->ti->t_sleep)) < \
		((2 * (*phi)->ti->t_eat) - 5)) && ((*phi)->cycle == 2) && \
		((*phi)->ti->n_philo % 2 == 1) && \
		((*phi)->ti->n_philo == (*phi)->phi_num))
	{
		while (((*phi)->time - (*phi)->o_time) < ((*phi)->ti->t_die))
			ft_get_current_time(&(*phi));
	}
	else
	{
		(*phi)->cycle = 2;
		return (0);
	}
		(*phi)->cycle = 2;
	return (1);
}

static void	ft_i_am_alive(t_phi **phi)
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
}

void	ft_taking_fork(t_phi **phi)
{
	if ((ft_am_i_dead(&(*phi)) == 1) && (((*phi)->ti->n_philo) > 1))
	{
		(*phi)->d_state = 1;
		ft_dying_state(&(*phi));
		return ;
	}
	else
		ft_i_am_alive(&(*phi));
	if ((*phi)->ti->philo_1 == 0)
		ft_taking_fork_time(&(*phi));
	if ((*phi)->d_state == 1)
		return ;
	else
		ft_taking_fork_print(&(*phi));
}
