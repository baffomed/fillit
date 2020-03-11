/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:20:24 by wharghaz          #+#    #+#             */
/*   Updated: 2019/09/20 15:04:07 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (!(*s2))
		return ((char *)s1);
	while (*s1 != '\0' && n-- >= ft_strlen(s2))
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char *)s1);
		++s1;
	}
	return (NULL);
}
