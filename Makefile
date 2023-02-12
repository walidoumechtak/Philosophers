# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:08:11 by woumecht          #+#    #+#              #
#    Updated: 2023/02/12 13:33:31 by woumecht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=philo

OBJ=philo.o \
	Error_check.o \
	convert_time.o \
	helped_functions/ft_atoi.o \
	helped_functions/get_current_time.o \
	case_of_philo/cases_of_philo.o
#helped_functions/ft_split.o \

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