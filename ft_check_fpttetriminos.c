/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fpttetriminos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <wharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:39:30 by wharghaz          #+#    #+#             */
/*   Updated: 2020/02/08 18:57:42 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fig_firstcheck(char **line)
{
	int i;
	int	e;

	e = 2;
	i = 0;
	while (i < 4)
	{
		if (line[i][0] == '#' && line[i][1] == '#' &&
			line[i][2] == '#' && line[i][3] == '#')
			return (1);
		if (line[0][i] == '#' && line[1][i] == '#' &&
			line[2][i] == '#' && line[3][i] == '#')
			return (1);
		while (e < 4 && i < 3)
		{
			if (line[i][e] == '#' && line[i + 1][e] == '#' &&
				line[i + 1][e - 1] == '#' && line[i + 1][e - 2] == '#')
				return (1);
			++e;
		}
		e = 2;
		++i;
	}
	return (0);
}

int		ft_fig_secondcheck(char **line)
{
	int i;
	int e;

	i = 0;
	e = 0;
	while (i < 3)
	{
		while (e < 3)
		{
			if (line[i][e] == '#' && line[i][e + 1] == '#' &&
				line[i + 1][e] == '#' && line[i + 1][e + 1] == '#')
				return (1);
			++e;
		}
		e = 0;
		++i;
	}
	return (0);
}

int		ft_fig_thirdcheck(char **line)
{
	int i;
	int e;

	i = 0;
	e = 1;
	while (i < 3)
	{
		while (e < 3)
		{
			if (line[i][e] == '#' && line[i][e + 1] &&
				line[i + 1][e - 1] == '#' && line[i + 1][e] == '#')
				return (1);
			if (line[i][e] == '#' && line[i + 1][e - 1] == '#' &&
				line[i + 1][e] == '#' && line[i + 1][e + 1] == '#')
				return (1);
			++e;
		}
		e = 1;
		++i;
	}
	return (0);
}

int		ft_fig_fourthcheck(char **line)
{
	int i;
	int e;

	i = 0;
	e = 1;
	while (i < 2)
	{
		while (e < 4)
		{
			if (line[i][e] == '#' && line[i + 1][e] == '#' &&
				line[i + 1][e - 1] == '#' && line[i + 2][e - 1] == '#')
				return (1);
			if (line[i][e] == '#' && line[i + 1][e] == '#' &&
				line[i + 2][e] == '#' && line[i + 2][e - 1] == '#')
				return (1);
			if (line[i][e] == '#' && line[i + 1][e] == '#' &&
				line[i + 1][e - 1] == '#' && line[i + 2][e] == '#')
				return (1);
			++e;
		}
		e = 1;
		++i;
	}
	return (0);
}

int		ft_fig_fifthcheck(char **line)
{
	int i;
	int e;

	i = 0;
	e = 0;
	while (i < 2)
	{
		while (e < 3)
		{
			if (line[i][e] == '#' && line[i + 1][e] == '#' &&
				line[i + 1][e + 1] == '#' && line[i + 2][e + 1] == '#')
				return (1);
			if (line[i][e] == '#' && line[i][e + 1] == '#' &&
				line[i + 1][e + 1] == '#' && line[i + 2][e + 1] == '#')
				return (1);
			if (line[i][e] == '#' && line[i + 1][e] == '#' &&
				line[i + 2][e] == '#' && line[i + 2][e + 1] == '#')
				return (1);
			++e;
		}
		e = 0;
		++i;
	}
	return (0);
}
