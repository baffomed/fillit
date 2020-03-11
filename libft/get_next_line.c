/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <wharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:43:33 by wharghaz          #+#    #+#             */
/*   Updated: 2019/12/06 13:39:05 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check_line(char **s, char **line, int i, int fd)
{
	char	*tmp;
	int		bsn;

	bsn = 0;
	while (*(s[fd] + bsn) != '\n' && *(s[fd] + bsn) != '\0')
		++bsn;
	if (*(s[fd] + bsn) == '\n')
	{
		*line = ft_strsub(s[fd], 0, bsn);
		tmp = ft_strdup(s[fd] + bsn + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (*(s[fd] + bsn) == '\0')
	{
		if (i == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[4096];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			i;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (i < 0)
		return (-1);
	else if (i == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_check_line(s, line, i, fd));
}
