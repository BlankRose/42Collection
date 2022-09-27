# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 13:58:51 by flcollar          #+#    #+#              #
#    Updated: 2022/05/28 23:06:48 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

NAME = bsp
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
DEFINES = -D PRECISION=8
DANGER = -fsanitize=address
COMPILER = c++

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

FONCTIONS = main.cpp bsp.cpp
CLASSES = Fixed.cpp Point.cpp

SRC = $(CLASSES) $(FONCTIONS)
OBJ = $(SRC:.cpp=.o)

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE'S RULES             #
# *                                      * #
#==--------------------------------------==#

all: $(NAME)

.cpp.o:
	@$(COMPILER) $(FLAGS) $(DEFINES) -o $@ -c $<

$(NAME): $(OBJ)
	@$(COMPILER) $(DANGER) $(OBJ) -o $(NAME)
	@printf "\033[32mThe programm $(NAME) has been compiled successfully!\033[0m\n"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re