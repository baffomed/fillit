/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:58:20 by wharghaz          #+#    #+#             */
/*   Updated: 2019/11/21 20:58:39 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*buff;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (!(buff = (char *)(malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	while (len-- >= 0)
	{
		buff[i] = str[i];
		i++;
	}
	return (buff);
}
