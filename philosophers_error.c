/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:56:55 by corellan          #+#    #+#             */
/*   Updated: 2023/02/17 20:58:02 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error_message(t_data *p)
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
