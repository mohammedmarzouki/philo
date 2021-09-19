# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/18 13:14:44 by mmarzouk          #+#    #+#              #
#    Updated: 2021/09/18 13:15:10 by mmarzouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

SRCS = check_assign.c philo.c

all:$(NAME)

$(NAME): $(SRCS)
	@gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -rf $(NAME)
	
fclean: clean

re : fclean all

.PHONY: all clean fclean re