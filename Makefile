# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/05/13 13:07:44 by flcollar         ###   ########.fr        #
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

CORE_FOLDER = ./core/
CORE_FILES = main.c signals.c
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

$(NAME): dependency $(OBJ)
	@gcc $(DANGER) -lreadline -L$(LIB_FOLDER) -l$(LIB_NAME) -L$(PIPEX_FOLDER) -l$(PIPEX_NAME) $(OBJ) -o $(NAME)
	@printf "\033[32mThe programm $(NAME) has been compiled successfully!\033[0m\n"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

aclean: fclean
	@make fclean -sC $(LIB_FOLDER)
	@make fclean -sC $(PIPEX_FOLDER)

re: aclean all

.PHONY: all clean fclean aclean re
