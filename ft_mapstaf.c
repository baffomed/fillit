/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapstaf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <wharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:09:08 by wharghaz          #+#    #+#             */
/*   Updated: 2020/02/11 21:59:53 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_exit(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int			ft_minpossqu(t_tlist *start)
{
	int		i;
	int		sqrt;
	t_tlist	*begin;

	begin = start;
	i = 0;
	sqrt = 1;
	while (begin != NULL)
	{
		i++;
		begin = begin->next;
	}
	i *= 4;
	while (sqrt * sqrt < i)
		++sqrt;
	i = sqrt * sqrt;
	return (sqrt);
}

void		ft_print_map(char **map, int size)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y < size)
	{
		while (x < size)
		{
			ft_putchar(map[y][x]);
			++x;
		}
		ft_putchar('\n');
		x = 0;
		++y;
	}
}

char		**ft_create_map(int size)
{
	char	**map;
	int		i;
	int		e;

	i = 0;
	e = 0;
	map = (char**)malloc(size * (sizeof(char*)));
	while (i < size)
	{
		map[i] = (char*)malloc(size * (sizeof(char*)));
		++i;
	}
	i = 0;
	while (i < size)
	{
		while (e < size)
		{
			map[i][e] = '.';
			++e;
		}
		e = 0;
		++i;
	}
	return (map);
}

void		ft_dellist(t_tlist *list)
{
	t_tlist	*cur_list;
	t_tlist	*next_list;

	if (list)
	{
		cur_list = list;
		while (cur_list)
		{
			next_list = cur_list->next;
			free(cur_list);
			cur_list = next_list;
		}
		list = NULL;
	}
}
