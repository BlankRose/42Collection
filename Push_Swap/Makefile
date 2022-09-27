# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 15:13:36 by flcollar          #+#    #+#              #
#    Updated: 2022/05/10 14:42:50 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

NAME = push_swap
FLAGS = $(DANGER) -Wall -Werror -Wextra
DANGER = -fsanitize=address -g3

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

LIB_FOLDER = ./libft/
LIB_NAME = ft
LIB = $(addprefix $(LIB_FOLDER), $(LIB_NAME))

R_FOLDER = ./rules/
R_FILES = swap.c push.c rotate.c rotaterev.c
R_SRC = $(addprefix $(R_FOLDER), $(R_FILES))

A_FOLDER = ./algo/
A_FILES = main.c args.c utils.c sort_small.c sort_big.c
A_SRC = $(addprefix $(A_FOLDER), $(A_FILES))

SRC = $(R_SRC) $(A_SRC)
OBJ = $(SRC:.c=.o)

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE'S RULES             #
# *                                      * #
#==--------------------------------------==#

all: $(NAME)

dependency:
	@make -sC $(LIB_FOLDER)

.c.o:
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): dependency $(OBJ)
	@gcc $(DANGER) -L$(LIB_FOLDER) -l$(LIB_NAME) -o $(NAME) $(OBJ)
	@printf "\033[32mThe programm $(NAME) has been compiled successfully!\033[0m\n"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

aclean: fclean
	@make fclean -C $(LIB_FOLDER)

re: aclean all

.PHONY: all dependency clean fclean aclean
