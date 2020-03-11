/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:17:15 by wharghaz          #+#    #+#             */
/*   Updated: 2019/09/20 14:25:49 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s2);
	if (i < n)
	{
		str = ft_memcpy(s1, s2, i);
		ft_bzero(str + i, n - i);
	}
	else
		str = ft_memcpy(s1, s2, n);
	return (str);
}
