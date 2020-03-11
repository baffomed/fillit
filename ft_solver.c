/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <wharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:32:02 by wharghaz          #+#    #+#             */
/*   Updated: 2020/02/11 21:30:31 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_borders(char **map, t_tlist *elem, int *cord, int border)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (((cord[1] + elem->x[i]) < border) &&
			((cord[0] + elem->y[i]) < border) &&
			map[cord[0] + elem->y[i]][cord[1] + elem->x[i]] == '.')
			++i;
		else
			return (0);
	}
	return (1);
}

void		ft_place_fig(char **map, t_tlist *list, int *cord)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[cord[0] + list->y[i]][cord[1] + list->x[i]] = list->letter;
		++i;
	}
}

void		ft_delete_fig(char **map, t_tlist *list, int *cord)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[cord[0] + list->y[i]][cord[1] + list->x[i]] = '.';
		++i;
	}
}

int			ft_filler(t_tlist *list, char **map, int size)
{
	int		cord[2];

	cord[0] = 0;
	while (cord[0] < size && list != NULL)
	{
		cord[1] = 0;
		while (cord[1] < size)
		{
			if (ft_check_borders(map, list, cord, size))
			{
				ft_place_fig(map, list, cord);
				if (!(ft_filler(list->next, map, size)))
					ft_delete_fig(map, list, cord);
				else
					return (1);
			}
			++cord[1];
		}
		++cord[0];
	}
	if (list != NULL)
		return (0);
	return (1);
}

int			ft_solver(t_tlist *start)
{
	char	**map;
	int		minsqu;

	map = NULL;
	minsqu = ft_minpossqu(start);
	map = ft_create_map(minsqu);
	while (!(ft_filler(start, map, minsqu)))
	{
		(map != NULL) ? ft_arrdel(map, minsqu) : 0;
		map = ft_create_map(++minsqu);
	}
	ft_print_map(map, minsqu);
	(map != NULL) ? ft_arrdel(map, minsqu) : 0;
	ft_dellist(start);
	return (0);
}
