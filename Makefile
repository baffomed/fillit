# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wharghaz <wharghaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 20:26:42 by wharghaz          #+#    #+#              #
#    Updated: 2020/02/11 21:59:30 by wharghaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

MAIN = main.c

SRC = ft_solver.c ft_parser.c ft_check_fpttetriminos.c ft_check_spttetriminos.c ft_mapstaf.c

LIB = ./libft/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	@$(MAKE) -C $(LIB)
	gcc $(FLAGS) -o $(NAME) $(MAIN) $(SRC) ./libft/libft.a -I $(LIB)

clean:
	@$(MAKE) -C $(LIB) clean

fclean: clean
	@$(MAKE) -C $(LIB) fclean
	rm -f $(NAME)

re: fclean all
