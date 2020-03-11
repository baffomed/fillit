/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:36:22 by wharghaz          #+#    #+#             */
/*   Updated: 2019/09/23 21:51:16 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	it_isneg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoa(int n)
{
	int		tn;
	int		len;
	int		neg;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tn = n;
	len = 2;
	neg = 0;
	it_isneg(&n, &neg);
	while (tn /= 10)
		++len;
	len += neg;
	if (!(s = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	s[--len] = '\0';
	while (len--)
	{
		s[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
