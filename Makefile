# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:29:16 by corellan          #+#    #+#              #
#    Updated: 2023/02/12 19:27:35 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philosophers.c philosophers_utils.c philosophers_check_arg.c \
philosophers_list.c

OUT = philosophers.o philosophers_utils.o philosophers_check_arg.o \
philosophers_list.o

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