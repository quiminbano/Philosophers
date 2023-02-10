/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:34:41 by corellan          #+#    #+#             */
/*   Updated: 2023/02/10 17:41:46 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_error
{
	int	s_error;
	int	i;
}t_error;

typedef struct s_phi
{
	pthread_t		po;
	pthread_mutex_t mutex;
	int				phi_num;
	struct s_phi	*left;
	
	
}t_phi;

int		ft_check_valid_number(char const *str);
int		ft_check_is_number(char *str);
int		ft_atoi(char const *str);
size_t	ft_strlen(char const *str);

#endif
