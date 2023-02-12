/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:01:19 by corellan          #+#    #+#             */
/*   Updated: 2023/02/12 19:31:35 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_add_to_list(t_phi **begin, int num, char **av)
{
	t_phi	*new;
	t_phi	*iter;

	iter = *begin;
	new = ft_lstnew(num, av);
	if (*begin == NULL)
		*begin = new;
	else
	{
		while (iter->left != NULL)
			iter = iter->left;
		iter->left = new;
	}
}

t_phi	*ft_lstnew(int num, char **av)
{
	t_phi	*new;

	new = (t_phi *)malloc(sizeof(t_phi));
	if (new == NULL)
		return (NULL);
	new->phi_num = num;
	new->t_die = ft_atoi(av[2]);
	new->t_eat = ft_atoi(av[3]);
	new->t_sleep = ft_atoi(av[4]);
	new->f_state = 0;
	if (av[5] != NULL)
		new->ti_eat = ft_atoi(av[5]);
	new->left = NULL;
	return (new);
}

void	ft_print_list(t_phi **lst)
{
	t_phi	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		printf("%d -> ", temp->ti_eat);
		temp = temp->left;
	}
	printf("\n");
}
