/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:00:17 by wharghaz          #+#    #+#             */
/*   Updated: 2019/09/23 20:38:36 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*cur;

	if (!lst)
		return (NULL);
	cur = (*f)(lst);
	new = cur;
	while (lst->next)
	{
		lst = lst->next;
		if (!(cur->next = (*f)(lst)))
		{
			free(cur->next);
			return (NULL);
		}
		cur = cur->next;
	}
	return (new);
}
