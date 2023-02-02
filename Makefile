# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:08:11 by woumecht          #+#    #+#              #
#    Updated: 2023/02/02 13:35:15 by woumecht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=philo

OBJ=philo.o \
	helped_functions/ft_atoi.o \
	case_of_philo/cases_of_philo.o
#helped_functions/ft_split.o \

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -fsanitize=address

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ) 

re: fclean all

git:
	git add . && git commit -m "go .." && git push