# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 11:26:53 by flcollar          #+#    #+#              #
#    Updated: 2022/03/25 18:50:05 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

# The executable's name
# Nothing much to say here tbh
NAME = so_long

# The window's size ratio
# Tile Sizes will becomes: 16 pixels x ratio
WIN_RATIO = 3

# Defines the tiles set as follow:
# Wall / Ground / Spawn / Exit / Collectible / Enemy
TILE_SET = "10PECX"

#==--------------------------------------==#
# *                                      * #
#             PARAMETERS SETUP             #
# *                                      * #
#==--------------------------------------==#

FLAGS = -Wall -Werror -Wextra
DANGER = -fsanitize=address -g3

LIB_FOLDER = ./libft
LIB_NAMES = ft mlx
FRAMEWORKS = OpenGL AppKit

DEPENDENCIES = $(addprefix -L, $(LIB_FOLDER)) \
				$(addprefix -l, $(LIB_NAMES)) \
				$(addprefix -framework , $(FRAMEWORKS))

DEFINES = -D NAME=\"$(NAME)\"

FILES = main.c output.c maps.c windows.c \
		assets.c triggers.c events.c
FOLDER = ./scripts/

SRC = $(addprefix $(FOLDER), $(FILES))
OBJ = $(SRC:.c=.o)

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE'S RULES             #
# *                                      * #
#==--------------------------------------==#

all: $(NAME)

dependence:
	@make -C libft

.c.o:
	@gcc $(FLAGS) $(DEFINES) -o $@ -c $<

$(NAME): dependence $(OBJ)
	@gcc $(DANGER) $(DEPENDENCIES) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

aclean: fclean
	@make fclean -C libft

re: aclean all

test: re
	@./$(NAME) maps/*

.PHONY: all dependence clean fclean aclean re