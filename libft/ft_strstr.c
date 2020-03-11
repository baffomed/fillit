/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:08:55 by wharghaz          #+#    #+#             */
/*   Updated: 2019/09/19 20:21:04 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (!(*s1) && !(*s2))
		return ((char *)s1);
	while (*s1)
	{
		if (!(ft_strncmp(s1, s2, ft_strlen(s2))))
			return ((char *)s1);
		++s1;
	}
	return (NULL);
}
