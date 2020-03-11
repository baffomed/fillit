/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:58:56 by wharghaz          #+#    #+#             */
/*   Updated: 2019/11/21 21:01:40 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		length;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (*s1 || *s2)
		if (*s1)
			*str++ = *s1++;
		else if (*s2)
			*str++ = *s2++;
	*str = '\0';
	str = str - length;
	return (str);
}
