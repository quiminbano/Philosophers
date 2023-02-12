/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:19:49 by corellan          #+#    #+#             */
/*   Updated: 2023/02/12 19:27:12 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_initialize_problem(t_error *p, t_phi **phi, char **av)
{
	t_phi	*iter;

	iter = (*phi);
	p->n_philo = ft_atoi(av[1]);
	p->i = 1;
	while (p->i <= p->n_philo)
	{
		ft_add_to_list(&(iter), p->i, av);
		(p->i)++;
	}
	ft_print_list(&(iter));
}

static int	ft_error_message(t_error *p)
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
	t_error	p;
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
	ft_initialize_problem(&p, &phi, av);
	return (0);
}
