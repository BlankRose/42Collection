# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/05/20 20:14:12 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

NAME = minishell
FLAGS = -Wall -Werror -Wextra -g3
DANGER = $(FLAGS) -fsanitize=address

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

LIB_FOLDER = ./libft/
LIB_NAME = ft
LIBRARIES = -L$(LIB_FOLDER) -l$(LIB_NAME) \
			-I .brew/opt/readline/include \
			-lreadline

CORE_FOLDER = ./core/
CORE_FILES = main.c signals.c utils.c cmds.c lists.c \
			lexer.c init.c lists2.c parse.c word.c \
			prompt.c lexer2.c redirs.c
CORE_SRC = $(addprefix $(CORE_FOLDER), $(CORE_FILES))
CORE_OBJ = $(CORE_SRC:.c=.o)

PIPEX_FOLDER = ./pipexx/
PIPEX_FILES = pipex.c pipex-utils.c
PIPEX_SRC = $(addprefix $(PIPEX_FOLDER), $(PIPEX_FILES))
PIPEX_OBJ = $(PIPEX_SRC:.c=.o)

BUILTIN_FOLDER = ./builtin/
BUILTIN_FILES = env.c echo.c exit.c pwd.c export.c \
			unset.c cd.c
BUILTIN_SRC = $(addprefix $(BUILTIN_FOLDER), $(BUILTIN_FILES))
BUILTIN_OBJ = $(BUILTIN_SRC:.c=.o)

# ALL SOURCES TOGHETER
SRC = $(CORE_SRC) $(BUILTIN_SRC) $(PIPEX_SRC)
OBJ = $(CORE_OBJ) $(BUILTIN_OBJ) $(PIPEX_OBJ)

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE'S RULES             #
# *                                      * #
#==--------------------------------------==#

all: $(NAME)

.c.o:
	@gcc $(FLAGS) $(DEFINES) -o $@ -c $<

dependency:
	@make -sC $(LIB_FOLDER)

$(NAME): dependency $(OBJ)
	@gcc $(DANGER) $(LIBRARIES) $(OBJ) -o $(NAME)
	@printf "\033[32mThe programm $(NAME) has been compiled successfully!\033[0m\n"

clean:
	@rm -f $(OBJ)
	@make clean -sC $(LIB_FOLDER)

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC $(LIB_FOLDER)

re: fclean all

.PHONY: all builtin dependency clean fclean re
