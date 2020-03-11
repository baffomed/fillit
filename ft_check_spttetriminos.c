/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_spttetriminos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <wharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:43:15 by wharghaz          #+#    #+#             */
/*   Updated: 2020/02/11 21:27:58 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tlist		*ft_addelem(t_tlist *new)
{
	new = (t_tlist*)malloc(sizeof(t_tlist));
	new->next = NULL;
	return (new);
}

void		ft_arrdel(char **line, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(line[i]);
		++i;
	}
	free(line);
}

int			ft_fig_sixthcheck(char **line)
{
	int		i;
	int		e;

	i = 0;
	e = 0;
	while (i < 2)
	{
		while (e < 3)
		{
			if (line[i][e] == '#' && line[i][e + 1] == '#' &&
				line[i + 1][e] == '#' && line[i + 2][e] == '#')
				return (1);
			if (line[i][e] == '#' && line[i + 1][e] == '#' &&
				line[i + 1][e + 1] == '#' && line[i + 2][e] == '#')
				return (1);
			++e;
		}
		e = 0;
		++i;
	}
	return (0);
}

int			ft_fig_seventhcheck(char **line)
{
	int		i;
	int		e;

	i = 0;
	e = 0;
	while (i < 3)
	{
		while (e < 2)
		{
			if (line[i][e] == '#' && line[i][e + 1] == '#' &&
				line[i + 1][e + 1] == '#' && line[i + 1][e + 2] == '#')
				return (1);
			if (line[i][e] == '#' && line[i][e + 1] == '#' &&
				line[i][e + 2] == '#' && line[i + 1][e] == '#')
				return (1);
			if (line[i][e] == '#' && line[i][e + 1] == '#' &&
				line[i][e + 2] == '#' && line[i + 1][e + 2] == '#')
				return (1);
			++e;
		}
		e = 0;
		++i;
	}
	return (0);
}

int			ft_fig_eighthcheck(char **line)
{
	int		i;
	int		e;

	i = 0;
	e = 0;
	while (i < 3)
	{
		while (e < 2)
		{
			if (line[i][e] == '#' && line[i + 1][e] == '#' &&
				line[i + 1][e + 1] == '#' && line[i + 1][e + 2] == '#')
				return (1);
			if (line[i][e] == '#' && line[i][e + 1] == '#' &&
				line[i][e + 2] == '#' && line[i + 1][e + 1] == '#')
				return (1);
			++e;
		}
		e = 0;
		++i;
	}
	return (0);
}
