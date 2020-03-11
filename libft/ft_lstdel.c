/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:38:55 by wharghaz          #+#    #+#             */
/*   Updated: 2019/09/23 20:34:21 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *cur_list;
	t_list *next_list;

	cur_list = *alst;
	while (cur_list)
	{
		next_list = cur_list->next;
		(*del)(cur_list->content, cur_list->content_size);
		free(cur_list);
		cur_list = next_list;
	}
	*alst = NULL;
}
