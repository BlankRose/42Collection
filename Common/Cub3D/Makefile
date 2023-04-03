# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/05/30 15:19:19 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

NAME = cub3D

FLAGS = -Wall -Werror -Wextra -g3
DANGER = $(FLAGS) -fsanitize=address
MLXFLAGS = -l mlx -framework OpenGl -framework AppKit

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

LIB_FOLDER = ./libft/
LIB_NAME = ft
LIBRARIES = -L$(LIB_FOLDER) -l$(LIB_NAME)

CORE_FOLDER = ./core/
CORE_FILES = main.c utils.c parse.c parse2.c mlx_handler.c \
			verify.c display.c raycast.c maths.c drawing.c \
			init.c parse3.c movement.c display2.c
CORE_SRC = $(addprefix $(CORE_FOLDER), $(CORE_FILES))
CORE_OBJ = $(CORE_SRC:.c=.o)

# ALL SOURCES TOGHETER
SRC = $(CORE_SRC)
OBJ = $(CORE_OBJ)

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
	@gcc $(DANGER) $(LIBRARIES) $(MLXFLAGS) $(OBJ) -o $(NAME)
	@printf "\033[32mThe programm $(NAME) has been compiled successfully!\033[0m\n"

clean:
	@rm -f $(OBJ)
	@make clean -sC $(LIB_FOLDER)

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC $(LIB_FOLDER)

re: fclean all

.PHONY: all builtin dependency clean fclean re
