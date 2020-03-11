/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:30:41 by wharghaz          #+#    #+#             */
/*   Updated: 2019/09/20 19:57:39 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	num;
	int			neg;

	neg = 1;
	num = 0;
	while (*str && (*str == ' ' || *str == '\r' || *str == '\t' ||
				*str == '\n' || *str == '\v' || *str == '\f'))
		++str;
	if (*str && (*str == '-'))
		neg = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = (num * 10) + (*str - 48);
		++str;
		if (num * neg > 0 && neg == -1)
			return (0);
		if (num * neg < 0 && neg == 1)
			return (-1);
	}
	return (neg * num);
}
