/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:34:41 by corellan          #+#    #+#             */
/*   Updated: 2023/02/22 11:19:37 by corellan         ###   ########.fr       */
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

typedef struct s_data
{
	struct timeval	tp;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_s;
	pthread_mutex_t	mutex_time;
	struct s_phi	*begin;
	int				s_error;
	int				i;
	int				n_philo;
	int				philo_1;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ti_eat;
	int				die_st;
	int				philo_eat_c;
	long			s0;
	long			us0;
}t_data;

typedef struct s_phi
{
	pthread_t		po;
	pthread_mutex_t	mutex;
	struct timeval	tim;
	int				phi_num;
	int				f_state;
	int				eat_s;
	int				count_eat;
	int				d_state;
	int				e_counter;
	int				cycle;
	int				flag;
	int				flag_loop;
	long			s1;
	long			us1;
	long			time;
	long			o_time;
	t_data			*ti;
	struct s_phi	*left;
}t_phi;

int		ft_check_valid_number(char const *str);
int		ft_check_is_number(char *str);
int		ft_error_message(t_data *p);
int		ft_atoi(char const *str);
size_t	ft_strlen(char const *str);
t_phi	*ft_lstnew(int num, t_data *p);
void	ft_add_to_list(t_phi **begin, int num, t_data *p);
void	ft_print_list(t_phi **lst);
void	ft_get_current_time(t_phi **phi);
void	ft_get_current_time_small(t_phi **phi);
void	ft_wait_threads(t_phi **phi);
void	ft_routine_iter(t_phi *phi);
void	ft_thinking(t_phi **phi);
void	ft_taking_fork(t_phi **phi);
void	ft_eating(t_phi **phi);
void	ft_sleeping(t_phi **phi);
void	ft_dying_state(t_phi **phi);
void	ft_eating_state(t_phi **phi);
void	ft_unlock_mutexes(t_phi **phi);
void	ft_unlock(t_phi **phi);
void	ft_free_list(t_phi **phi);

#endif
