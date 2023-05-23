# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 02:51:55 by aennaouh          #+#    #+#              #
#    Updated: 2023/05/22 18:15:29 by aennaouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
B-NAME = 
cc = CC 
FLAGS= -Wall -Wextra -Werror -g #-fsanitize=address
HEAD = philosopher.h
SRC = condition_of_error.c philo_utilise.c philo_utilise1.c philo.c instraction.c philo_utilise2.c instraction_num_2.c\
 
OBJ = ${SRC:.c=.o}


all : $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)


clean : 
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME) 

re : fclean all
