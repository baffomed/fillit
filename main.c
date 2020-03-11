/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <wharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:37:16 by wharghaz          #+#    #+#             */
/*   Updated: 2020/02/12 21:54:45 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tlist		*ft_readandpars(t_tlist *list, int fd)
{
	int		i;
	int		z;
	char	buf[21];
	t_tlist	*list_curr;

	z = 0;
	i = read(fd, buf, 21);
	if (i == 0)
		ft_exit();
	list = ft_total_check(list, buf, i);
	list_curr = list;
	while ((i = read(fd, buf, 21)))
	{
		list_curr->next = ft_total_check(list, buf, i);
		list_curr = list_curr->next;
		z = i;
	}
	if (i == 0 && z == 21)
	{
		ft_dellist(list);
		ft_exit();
	}
	return (list);
}

int			main(int ac, char **av)
{
	int		letter;
	int		fd;
	t_tlist	*list;
	t_tlist	*first;

	list = NULL;
	first = NULL;
	letter = 65;
	if (ac == 2)
	{
		fd = open(*(av + 1), O_RDONLY);
		if (fd < 0)
			ft_exit();
		list = ft_readandpars(list, fd);
		first = list;
		while (first != NULL)
		{
			first->letter = letter;
			++letter;
			first = first->next;
		}
		ft_solver(list);
	}
	return (0);
}
