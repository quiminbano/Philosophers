/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:01:19 by corellan          #+#    #+#             */
/*   Updated: 2023/02/17 21:13:44 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_list(t_phi **phi)
{
	t_phi	*temp;
	t_phi	*temp2;

	temp2 = (*phi)->left;
	temp = (*phi);
	while (temp->left != NULL)
	{
		free(temp);
		temp = temp2;
		temp2 = temp2->left;
	}
	free(temp);
}

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
			iter = iter->left;
		iter->left = new;
	}
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
	new->eat_s = 0;
	new->count_eat = 0;
	new->left = NULL;
	return (new);
}

void	ft_print_list(t_phi **lst)
{
	t_phi	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		printf("%d -> ", temp->phi_num);
		temp = temp->left;
	}
	printf("\n");
}
