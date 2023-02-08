# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:29:16 by corellan          #+#    #+#              #
#    Updated: 2023/02/08 18:40:53 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philosophers.c

OUT = philosophers.o

FLAGS = -Wall -Wextra -Werror -pthread

CC = cc

all: $(NAME)

$(NAME): $(OUT)
		$(CC) $(FLAGS) $(OUT) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -I. -c $< -o $@

clean:
		rm -f $(OUT)

fclean: clean
		rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re bonus