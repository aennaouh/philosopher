# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 02:51:55 by aennaouh          #+#    #+#              #
#    Updated: 2023/06/22 16:13:19 by aennaouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc 
FLAGS= -Wall -Wextra -Werror
HEAD = philosopher.h
SRC = condition_of_error.c philo_utilise.c philo_utilise1.c philo.c instraction.c philo_utilise2.c instraction_num_2.c\

OBJ = ${SRC:.c=.o}

all : $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o philo

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
