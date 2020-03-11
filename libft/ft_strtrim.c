/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:59:13 by wharghaz          #+#    #+#             */
/*   Updated: 2019/09/19 21:54:56 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		--len;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		--len;
	if (len <= 0)
		len = 0;
	if (!(new = ft_strnew(len)))
		return (NULL);
	s = s + i;
	i = 0;
	while (i < len)
	{
		new[i] = *s;
		++i;
		++s;
	}
	return (new);
}
