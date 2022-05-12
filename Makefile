# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/05/12 17:52:31 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

NAME = minishell
FLAGS = -Wall -Werror -Wextra
DANGER = $(FLAGS) -fsanitize=address -g3

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

LIB_FOLDER = ./libft/
LIB_NAME = libft.a
LIB = $(addprefix $(LIB_FOLDER), $(LIB_NAME))

PIPEX_FOLDER = ./pipexx/
PIPEX_NAME = pipex.a
PIPEX = $(addprefix $(PIPEX_FOLDER), $(PIPEX_NAME))

CORE_FOLDER = ./minishell/
CORE_FILES = main.c
CORE = $(addprefix $(CORE_FOLDER), $(CORE_FILES))
CORE_OBJ = $(CORE:.c=.o)

BUILTIN_FOLDER = ./builtin/
BUILTIN_FILES = 
BUILTIN_SRC = $(addprefix $(BUILTIN_FOLDER), $(BUILTIN_FILES))
BUILTIN_OBJ = $(BUILTIN_SRC:.c=.o)

# ALL SOURCES TOGHETER
SRC = $(BUILTIN) $(CORE)
OBJ = $(SRC:.c=.o)

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE'S RULES             #
# *                                      * #
#==--------------------------------------==#

all: $(NAME)

dependency:
	@make -sC $(LIB_FOLDER)
	@make -sC $(PIPEX_FOLDER)

.c.o:
	@gcc $(FLAGS) $(DEFINES) -o $@ -c $<

$(NAME): $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

aclean: fclean
	@make fclean -sC $(LIB_FOLDER)
	@make fclean -sC $(PIPEX_FOLDER)

re: aclean all

.PHONY: all clean fclean aclean re
