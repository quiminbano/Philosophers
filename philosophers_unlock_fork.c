/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_unlock_fork.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:37:56 by corellan          #+#    #+#             */
/*   Updated: 2023/02/20 10:16:44 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_unlock_mutexes(t_phi **phi)
{
	(*phi)->f_state = 0;
	pthread_mutex_unlock(&((*phi)->mutex));
	if (((*phi)->ti->n_philo > 1) && ((*phi)->phi_num == (*phi)->ti->n_philo))
	{
		(*phi)->ti->begin->f_state = 0;
		pthread_mutex_unlock(&((*phi)->ti->begin->mutex));
	}
	else if (((*phi)->phi_num < (*phi)->ti->n_philo))
	{
		(*phi)->left->f_state = 0;
		pthread_mutex_unlock(&((*phi)->left->mutex));
	}
}

void	ft_unlock(t_phi **phi)
{
	pthread_mutex_unlock(&((*phi)->mutex));
	if (((*phi)->ti->n_philo > 1) && ((*phi)->phi_num == (*phi)->ti->n_philo))
		pthread_mutex_unlock(&((*phi)->ti->begin->mutex));
	else if (((*phi)->phi_num < (*phi)->ti->n_philo))
		pthread_mutex_unlock(&((*phi)->left->mutex));
}
