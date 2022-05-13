# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/05/13 20:23:29 by flcollar         ###   ########.fr        #
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
LIB_NAME = ft
PIPEX_FOLDER = ./pipexx/
PIPEX_NAME = pipex
LIBRARIES = -L$(LIB_FOLDER) -l$(LIB_NAME) \
			-L$(PIPEX_FOLDER) -l$(PIPEX_NAME) \
			-lreadline

CORE_FOLDER = ./core/
CORE_FILES = main.c signals.c utils.c cmds.c
CORE_SRC = $(addprefix $(CORE_FOLDER), $(CORE_FILES))
CORE_OBJ = $(CORE_SRC:.c=.o)

BUILTIN_FOLDER = ./builtin/
BUILTIN_FILES = env.c
BUILTIN_OUT = env
BUILTIN_SRC = $(addprefix $(BUILTIN_FOLDER)/src/, $(BUILTIN_FILES))
BUILTIN_OBJ = $(addprefix $(BUILTIN_FOLDER), $(BUILTIN_OUT))

# ALL SOURCES TOGHETER
SRC = $(CORE_SRC) $(BUILTIN_SRC)
OBJ = $(CORE_OBJ) $(BUILTIN_OBJ)

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE'S RULES             #
# *                                      * #
#==--------------------------------------==#

all: builtin $(NAME)

builtin:
	@gcc $(FLAGS) $(LIBRARIES) -o ./builtin/env ./builtin/src/env.c
	@gcc $(FLAGS) $(LIBRARIES) -o ./builtin/echo ./builtin/src/echo.c

dependency:
	@make -sC $(LIB_FOLDER)
	@make -sC $(PIPEX_FOLDER)

.c.o:
	@gcc $(FLAGS) $(DEFINES) -o $@ -c $<

$(NAME): dependency $(CORE_OBJ)
	@gcc $(DANGER) $(LIBRARIES) $(CORE_OBJ) -o $(NAME)
	@printf "\033[32mThe programm $(NAME) has been compiled successfully!\033[0m\n"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

aclean: fclean
	@make fclean -sC $(LIB_FOLDER)
	@make fclean -sC $(PIPEX_FOLDER)

re: aclean all

.PHONY: all builtin dependency clean fclean aclean re
