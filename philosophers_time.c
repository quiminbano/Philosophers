/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:43:59 by corellan          #+#    #+#             */
/*   Updated: 2023/02/15 16:58:11 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_get_current_time(t_phi **phi)
{
	gettimeofday(&((*phi)->tim), NULL);
	(*phi)->s1 = (*phi)->tim.tv_sec;
	(*phi)->us1 = (*phi)->tim.tv_usec;
	(*phi)->time = ((((*phi)->s1 - (*phi)->ti->s0) * 1000) + \
		(((*phi)->us1 - (*phi)->ti->us0) / 1000));
	usleep(500);
}

void	ft_usleep(long time)
{
	struct timeval	ti;
	struct timeval	tf;
	long			time;

	gettimeofday(&(ti), NULL);
	gettimeofday(&(tf), NULL);
	time = ((tf.tv_sec - ti.tv_sec) * 1000) + ();
}
