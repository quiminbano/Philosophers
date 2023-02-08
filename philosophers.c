/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:19:49 by corellan          #+#    #+#             */
/*   Updated: 2023/02/08 18:52:22 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(void)
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	printf("seconds: %ld\n miliseconds: %d\n", tp.tv_sec, (tp.tv_usec / 1000));
	gettimeofday(&tp, NULL);
	printf("seconds: %ld\n miliseconds: %d\n", tp.tv_sec, (tp.tv_usec / 1000));
	gettimeofday(&tp, NULL);
	printf("seconds: %ld\n miliseconds: %d\n", tp.tv_sec, (tp.tv_usec / 1000));
	gettimeofday(&tp, NULL);
	printf("seconds: %ld\n miliseconds: %d\n", tp.tv_sec, (tp.tv_usec / 1000));
	gettimeofday(&tp, NULL);
	printf("seconds: %ld\n miliseconds: %d\n", tp.tv_sec, (tp.tv_usec / 1000));
	gettimeofday(&tp, NULL);
	printf("seconds: %ld\n miliseconds: %d\n", tp.tv_sec, (tp.tv_usec / 1000));
	gettimeofday(&tp, NULL);
	printf("seconds: %ld\n miliseconds: %d\n", tp.tv_sec, (tp.tv_usec / 1000));
	return (0);
}