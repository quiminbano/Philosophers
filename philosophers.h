/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:34:41 by corellan          #+#    #+#             */
/*   Updated: 2023/02/12 19:26:31 by corellan         ###   ########.fr       */
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
	int	n_philo;
}t_error;

typedef struct s_phi
{
	pthread_t		po;
	pthread_mutex_t mutex;
	int				phi_num;
	int				f_state;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ti_eat;
	struct s_phi	*left;
	
	
}t_phi;

int		ft_check_valid_number(char const *str);
int		ft_check_is_number(char *str);
int		ft_atoi(char const *str);
size_t	ft_strlen(char const *str);
t_phi	*ft_lstnew(int num, char **av);
void	ft_add_to_list(t_phi **begin, int num, char **av);
void	ft_print_list(t_phi **lst);

#endif
