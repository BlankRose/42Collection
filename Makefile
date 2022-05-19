# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/05/17 20:41:10 by flcollar         ###   ########.fr        #
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
LIBRARIES = -L$(LIB_FOLDER) -l$(LIB_NAME) \
			-I .brew/opt/readline/include \
			-lreadline

CORE_FOLDER = ./core/
CORE_FILES = main.c signals.c utils.c cmds.c lists.c \
			lexer.c init.c lists2.c advsplit.c parse.c \
			prompt.c
CORE_SRC = $(addprefix $(CORE_FOLDER), $(CORE_FILES))
CORE_OBJ = $(CORE_SRC:.c=.o)

PIPEX_FOLDER = ./pipexx/
PIPEX_FILES = pipexcpy.c pipex-utils.c
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

fclean: clean
	@rm -f $(NAME)

aclean: fclean
	@make fclean -sC $(LIB_FOLDER)
	@make fclean -sC $(PIPEX_FOLDER)

re: aclean all

.PHONY: all builtin dependency clean fclean aclean re
