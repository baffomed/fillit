/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <wharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:02:35 by wharghaz          #+#    #+#             */
/*   Updated: 2020/02/12 21:42:45 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_validation(char **line)
{
	int		i;
	int		e;
	int		dot;

	i = 0;
	e = 0;
	dot = 0;
	if (line[0][4] != '\n' || line[1][4] != '\n' ||
		line[2][4] != '\n' || line[3][4] != '\n')
		return (0);
	while (i < 4)
	{
		while (e < 4)
		{
			if (line[i][e] != '.' && line[i][e] != '#')
				return (0);
			line[i][e] == '.' ? dot++ : 0;
			++e;
		}
		e = 0;
		++i;
	}
	if (dot != 12)
		return (0);
	return (1);
}

char		**ft_fromline_to_array(char *buf)
{
	char	**line;
	int		i;
	int		e;
	int		ex;

	i = 0;
	e = 0;
	ex = 0;
	line = (char**)malloc(4 * sizeof(char*));
	while (i < 4)
	{
		line[i] = (char*)malloc(5 * sizeof(char));
		while (e < 5)
		{
			line[i][e] = buf[ex];
			++e;
			++ex;
		}
		e = 0;
		++i;
	}
	return (line);
}

t_tlist		*ft_total_check(t_tlist *list, char *buf, int n)
{
	char	**line;
	int		i;

	i = 0;
	line = ft_fromline_to_array(buf);
	if ((!ft_validation(line)) || (n < 20 && n != 0))
	{
		ft_dellist(list);
		ft_arrdel(line, 4);
		ft_exit();
	}
	if ((!ft_fig_firstcheck(line)) && (!ft_fig_secondcheck(line)) &&
		(!ft_fig_thirdcheck(line)) && (!ft_fig_fourthcheck(line)) &&
		(!ft_fig_fifthcheck(line)) && (!ft_fig_sixthcheck(line)) &&
		(!ft_fig_seventhcheck(line)) && (!ft_fig_eighthcheck(line)))
	{
		ft_dellist(list);
		ft_arrdel(line, 4);
		ft_exit();
	}
	return (ft_fromarray_to_list(line, i));
}

t_tlist		*ft_fromarray_to_list(char **line, int i)
{
	t_tlist	*new_elem;
	int		ex;
	int		e;

	ex = 0;
	e = 0;
	new_elem = NULL;
	new_elem = ft_addelem(new_elem);
	while (e < 4)
	{
		while (ex < 4)
		{
			if (line[e][ex] == '#')
			{
				new_elem->x[i] = ex;
				new_elem->y[i] = e;
				++i;
			}
			++ex;
		}
		ex = 0;
		++e;
	}
	ft_arrdel(line, 4);
	return (ft_upperleft(new_elem));
}

t_tlist		*ft_upperleft(t_tlist *elem)
{
	int		ix;
	int		iy;
	int		e;

	e = 1;
	iy = elem->y[0];
	ix = elem->x[0];
	while (e < 4)
	{
		if (ix > elem->x[e])
			ix = elem->x[e];
		if (iy > elem->y[e])
			iy = elem->y[e];
		++e;
	}
	e = 0;
	while (e < 4)
	{
		elem->x[e] -= ix;
		elem->y[e] -= iy;
		++e;
	}
	return (elem);
}
