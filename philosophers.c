/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:19:49 by corellan          #+#    #+#             */
/*   Updated: 2023/02/20 19:32:20 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ft_start_routine(void *p)
{
	t_phi		*phi;

	phi = (t_phi *)p;
	ft_wait_threads(&(phi));
	while ((phi->d_state == 0) && (phi->ti->philo_1 == 0) && \
		(phi->e_counter < phi->ti->n_philo))
	{
		ft_routine_iter(&(*phi));
		if (phi->d_state == 1 && phi->ti->philo_1 == 0)
			break ;
		if (phi->e_counter >= phi->ti->n_philo)
			break ;
	}
	return (NULL);
}

static int	ft_prepare_threads_aux(t_phi **phi)
{
	t_phi	*temp;

	temp = (*phi);
	while (temp != NULL)
	{
		pthread_join((temp->po), NULL);
		temp = temp->left;
	}
	temp = (*phi);
	while (temp != NULL)
	{
		pthread_mutex_destroy(&(temp->mutex));
		temp = temp->left;
	}
	pthread_mutex_destroy(&((*phi)->ti->mutex_dead));
	pthread_mutex_destroy(&((*phi)->ti->mutex_s));
	pthread_mutex_destroy(&((*phi)->ti->mutex_time));
	if ((*phi)->ti->ti_eat != 0)
		pthread_mutex_destroy(&((*phi)->ti->mutex_eat));
	ft_free_list(&(*phi));
	return (0);
}

static int	ft_prepare_threads(t_phi **phi)
{
	t_phi	*temp;

	temp = (*phi);
	(*phi)->ti->i = 0;
	pthread_mutex_init(&(*phi)->ti->mutex_dead, NULL);
	pthread_mutex_init(&(*phi)->ti->mutex_s, NULL);
	pthread_mutex_init(&(*phi)->ti->mutex_time, NULL);
	if (temp->ti->ti_eat != 0)
		pthread_mutex_init(&(*phi)->ti->mutex_eat, NULL);
	while (temp != NULL)
	{
		pthread_mutex_init(&(temp->mutex), NULL);
		temp = temp->left;
	}
	temp = (*phi);
	while (temp != NULL)
	{
		pthread_create(&(temp->po), NULL, &ft_start_routine, &(*temp));
		if ((temp->phi_num % 2) == 1)
			usleep(3000);
		temp = temp->left;
	}
	return (ft_prepare_threads_aux(&(*phi)));
}

static int	ft_initialize_problem(t_data *p, t_phi **phi, char **av)
{
	p->n_philo = ft_atoi(av[1]);
	p->i = 1;
	p->die_st = 0;
	p->philo_1 = 0;
	p->philo_eat_c = 0;
	p->t_die = ft_atoi(av[2]);
	p->t_eat = ft_atoi(av[3]);
	p->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		p->ti_eat = ft_atoi(av[5]);
	else
		p->ti_eat = 0;
	while (p->i <= p->n_philo)
	{
		ft_add_to_list(&(*phi), p->i, p);
		(p->i)++;
	}
	p->begin = (*phi);
	return (ft_prepare_threads(&(*phi)));
}

int	main(int ac, char **av)
{
	t_data	p;
	t_phi	*phi;

	p.i = 1;
	phi = NULL;
	if (ac < 5 || ac > 6)
	{
		p.s_error = 1;
		return (ft_error_message(&p));
	}
	p.s_error = 2;
	while (av[p.i] != NULL)
	{
		if (ft_check_is_number(av[p.i]) == 1)
			return (ft_error_message(&(p)));
		if (ft_check_valid_number(av[p.i]) == 1)
			return (ft_error_message(&(p)));
		(p.i)++;
	}
	return (ft_initialize_problem(&p, &phi, av));
}
