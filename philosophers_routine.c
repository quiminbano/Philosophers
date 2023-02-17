/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:03:50 by corellan          #+#    #+#             */
/*   Updated: 2023/02/17 21:52:02 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_routine_iter(t_phi *phi)
{
	if (phi->ti->die_st == 0 && (phi->ti->philo_eat_c < phi->ti->n_philo))
		ft_thinking(&phi);
	if (phi->ti->die_st == 0 && (phi->ti->philo_eat_c < phi->ti->n_philo))
		ft_taking_fork(&phi);
	if ((phi->ti->die_st == 0) && (phi->ti->philo_1 == 0) && \
		(phi->ti->philo_eat_c < phi->ti->n_philo))
		ft_eating(&phi);
	if ((phi->ti->die_st == 0) && (phi->ti->philo_1 == 0) && \
		(phi->ti->philo_eat_c < phi->ti->n_philo))
		ft_sleeping(&phi);
	if ((phi->ti->die_st == 0) && (phi->ti->philo_1 == 0) && \
		(phi->ti->philo_eat_c < phi->ti->n_philo))
	{
		if (phi->ti->ti_eat > 0)
			ft_eating_state(&phi);
	}
}

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
			ft_dying_state(&(*phi));
			ft_unlock_mutexes(&(*phi));
			return ;
		}
	}
	ft_unlock_mutexes(&(*phi));
	if ((*phi)->ti->ti_eat > 0)
		((*phi)->count_eat)++;
}

void	ft_sleeping(t_phi **phi)
{
	printf("%ldms %d is sleeping.\n", (*phi)->time, (*phi)->phi_num);
	while (((*phi)->time - (*phi)->o_time - (*phi)->ti->t_eat) < (*phi)->ti->t_sleep)
	{
		ft_get_current_time(&(*phi));
		if (((*phi)->time - (*phi)->o_time) >= (*phi)->ti->t_die)
		{
			ft_dying_state(&(*phi));
			return ;
		}
	}
	usleep(500);
}
