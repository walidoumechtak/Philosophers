# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:08:11 by woumecht          #+#    #+#              #
#    Updated: 2023/02/27 11:51:35 by woumecht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror 
NAME=philo

OBJ=main.o \
	Error_check.o \
	convert_time.o \
	ft_atoi.o \
	get_current_time.o \
	cases_of_philo.o \
	init.o \
	destroy.o \
	putstr_error.o \
	ft_sleep.o \

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ) 

re: fclean all

git:
	git add . && git commit -m "go .." && git push
