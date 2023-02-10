/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_check_arg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:25:58 by corellan          #+#    #+#             */
/*   Updated: 2023/02/09 14:15:13 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_is_number(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	while ((str[i] <= 57 && str[i] >= 48))
		i++;
	if (i < ft_strlen(str))
		return (1);
	return (0);
}

int	ft_check_valid_number(char const *str)
{
	int			i;
	long long	num;
	long long	neg;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	if ((num < 0) || ((num * neg) > 2147483647) || ((num * neg) < 1))
		return (1);
	return (0);
}
