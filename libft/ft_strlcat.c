/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:16:19 by wharghaz          #+#    #+#             */
/*   Updated: 2019/09/17 17:16:37 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t res;

	j = 0;
	i = 0;
	while (dst[i] != '\0')
		++i;
	res = 0;
	while (src[res] != '\0')
		++res;
	if (n <= i)
		res += n;
	else
		res += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
