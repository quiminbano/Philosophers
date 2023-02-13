/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:19:49 by corellan          #+#    #+#             */
/*   Updated: 2023/02/13 16:46:05 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ft_start_routine(t_phi *phi)
{
	while (phi->ti->die_st == 0)
	{
		if (phi->ti->die_st == 0)
			ft_taking_fork(&phi);
		if (phi->ti->die_st == 0)
			ft_eating(&phi);
		if (phi->ti->die_st == 0)
			ft_sleeping(&phi);
		if (phi->ti->die_st == 0)
			ft_thinking(&phi);
		if (phi->ti->die_st == 1)
			break ;
	}
	return (NULL);
}

static int	ft_prepare_threads(t_phi **phi)
{
	t_phi	*temp;

	temp = *phi;
	while (temp != NULL)
	{
		pthread_mutex_init(&(temp->mutex), NULL);
		pthread_create(&(temp->po), NULL, &ft_start_routine, &(*temp));
		temp = temp->left;
	}
}

static int	ft_initialize_problem(t_data *p, t_phi **phi, char **av)
{
	p->n_philo = ft_atoi(av[1]);
	p->i = 1;
	gettimeofday(&(p->tp), NULL);
	p->s0 = p->tp.tv_sec;
	p->us0 = p->tp.tv_usec;
	p->die_st = 0;
	p->t_die = ft_atoi(av[2]);
	p->t_eat = ft_atoi(av[3]);
	p->t_sleep = ft_atoi(av[4]);
	if (av[5] != NULL)
		p->ti_eat = ft_atoi(av[5]);
	while (p->i <= p->n_philo)
	{
		ft_add_to_list(&(*phi), p->i, p);
		(p->i)++;
	}
	return (ft_prepare_threads(&(*phi)));
}

static int	ft_error_message(t_data *p)
{
	if (p->s_error == 1)
	{
		write(2, "philo: Input not valid.\n", 24);
		write(2, "Usage:\n./philo number_philosophers time_die ", 44);
		write(2, "time_eat time_sleep [n_times_eat(optional)]\n", 44);
		write(2, "time_die, time_eat, time_sleep should be express", 48);
		write(2, " in milliseconds(ms).\n", 22);
	}
	if (p->s_error == 2)
	{
		write(2, "philo: Input not valid.\n", 24);
		write(2, "You must write only positive numbers, and they ", 47);
		write(2, "must be between 1 ann MAX_INT\n", 30);
	}
	return (1);
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
