/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:01:19 by corellan          #+#    #+#             */
/*   Updated: 2023/02/13 21:10:34 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_add_to_list(t_phi **begin, int num, t_data *p)
{
	t_phi	*new;
	t_phi	*iter;

	iter = *begin;
	new = ft_lstnew(num, p);
	if (*begin == NULL)
		*begin = new;
	else
	{
		while (iter->left != NULL)
		{
			iter->begin = *begin;
			iter = iter->left;
		}
		iter->left = new;
	}
	new->begin = *begin;
}

t_phi	*ft_lstnew(int num, t_data *p)
{
	t_phi	*new;

	new = (t_phi *)malloc(sizeof(t_phi));
	if (new == NULL)
		return (NULL);
	new->phi_num = num;
	new->f_state = 0;
	new->ti = p;
	new->left = NULL;
	return (new);
}

void	ft_print_list(t_phi **lst)
{
	t_phi	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		printf("%d -> ", temp->ti->t_die);
		temp = temp->left;
	}
	printf("\n");
}
