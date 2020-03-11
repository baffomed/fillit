/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wharghaz <wharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:56:53 by wharghaz          #+#    #+#             */
/*   Updated: 2020/02/12 19:50:13 by wharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef	struct		s_tlist
{
	char			y[4];
	char			x[4];
	char			letter;
	struct s_tlist	*next;
}					t_tlist;

void				ft_exit(void);
int					ft_validation(char **line);
int					ft_fig_firstcheck(char **line);
int					ft_fig_secondcheck(char **line);
int					ft_fig_thirdcheck(char **line);
int					ft_fig_fourthcheck(char **line);
int					ft_fig_fifthcheck(char **line);
int					ft_fig_sixthcheck(char **line);
int					ft_fig_seventhcheck(char **line);
int					ft_fig_eighthcheck(char **line);
t_tlist				*ft_total_check(t_tlist *new_elem, char *buf, int n);
void				ft_arrdel(char **line, int size);
void				ft_dellist(t_tlist *list);
t_tlist				*ft_addelem(t_tlist *new);
t_tlist				*ft_fromarray_to_list(char **line, int i);
t_tlist				*ft_upperleft(t_tlist *elem);
t_tlist				*ft_readandpars(t_tlist *list, int fd);
char				**ft_create_map(int size);
int					ft_minpossqu(t_tlist *start);
int					ft_solver(t_tlist *start);
void				ft_print_map(char **map, int size);
char				**ft_fromline_to_array(char *buf);
#endif
