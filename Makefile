# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:29:16 by corellan          #+#    #+#              #
#    Updated: 2023/02/19 19:12:27 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philosophers.c philosophers_utils.c philosophers_check_arg.c \
philosophers_list.c philosophers_time.c philosophers_routine.c \
philosophers_unlock_fork.c philosophers_routine_forks.c \
philosophers_state.c philosophers_error.c

OUT = philosophers.o philosophers_utils.o philosophers_check_arg.o \
philosophers_list.o philosophers_time.o philosophers_routine.o \
philosophers_unlock_fork.o philosophers_routine_forks.o \
philosophers_state.o philosophers_error.o

FLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g -static-libasan

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
