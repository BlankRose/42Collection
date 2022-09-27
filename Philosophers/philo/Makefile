# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 16:59:41 by flcollar          #+#    #+#              #
#    Updated: 2022/05/12 23:24:25 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==--------------------------------------==#
# *                                      * #
#              GLOBAL SETTINGS             #
# *                                      * #
#==--------------------------------------==#

NAME = philo
FLAGS = -Wall -Werror -Wextra
DANGER = -fsanitize=address -g3

FOLDER = ./scripts/
FILES = main.c runtime.c threads.c init.c output.c utils.c
SRC = $(addprefix $(FOLDER), $(FILES))
OBJ = $(SRC:.c=.o)

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE'S RULES             #
# *                                      * #
#==--------------------------------------==#

all: $(NAME)

.c.o:
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@gcc $(DANGER) -o $(NAME) $(OBJ)
	@printf "\033[32mThe programm $(NAME) has been compiled successfully!\033[0m\n"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all dependency clean fclean