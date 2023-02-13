# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woumecht <woumecht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 11:00:35 by woumecht          #+#    #+#              #
#    Updated: 2023/02/13 12:30:55 by woumecht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Wextra -Werror
NAME=philo_bonus

#ANSI escape code

NONE	=	'\033[0m'
GREEN	=	'\033[32m'
RED		=	'\033[91m'
GRAY	=	'\033[2;37m'
ITALIC	=	'\033[3m'


SRC = main_bonus.c


OBJ = $(SRC:.c=.o)

.c.o	:
			@$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(GRAY)" compiling ..." $(NONE)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo $(GREEN)"\tcompiled " $(NONE)

clean:
	@rm -f $(OBJ)
	@echo $(RED) "\tall object files are cleaned" $(NONE)

fclean: clean
	@rm -f $(NAME)
	@echo $(RED) "\tall are cleaned" $(NONE)

re: fclean all

git:
	git add * && git commit -m "go" && git push