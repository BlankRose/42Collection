# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:48:03 by flcollar          #+#    #+#              #
#    Updated: 2022/05/18 16:46:21 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
DANGER = $(FLAGS) -fsanitize=address -g3

BUFFER_SIZE = 10000
DEFINES = -D BUFFER_SIZE=$(BUFFER_SIZE)

TEST_FILE = ./main.c
TEST_OUT = test

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

# STRING MANIPULATIONS
STRING_FOLDER = strings/
STRING_FILES = is_alphanum.c is_special.c is_set.c set_char.c set_string.c \
			   duplicate.c split.c compare.c strLength.c applyFunc.c search.c \
			   join.c
STRING = $(addprefix $(STRING_FOLDER), $(STRING_FILES))

# MEMORY MANIPULATIONS
MEMORY_FOLDER = memory/
MEMORY_FILES = allocations.c changeMem.c checkMem.c free.c
MEMORY = $(addprefix $(MEMORY_FOLDER), $(MEMORY_FILES))

# CONVERTERS
CONVERT_FOLDER = converters/
CONVERT_FILES = itoa.c bases.c bases2.c strings.c misc.c
CONVERT = $(addprefix $(CONVERT_FOLDER), $(CONVERT_FILES))

# MATHEMATICS
MATHS_FOLDER = maths/
MATHS_FILES = limits.c nbrLength.c power.c overflow.c range.c divide.c
MATHS = $(addprefix $(MATHS_FOLDER), $(MATHS_FILES))

# DATA MANAGER
DATA_FOLDER = data/
DATA_FILES = list_create.c list_modify.c list_destroy.c list_fetch.c \
			btree_create.c btree_destroy.c struct_init.c sort.c
DATA = $(addprefix $(DATA_FOLDER), $(DATA_FILES))

# IN & OUT HANDLERS
IN_OUT_FOLDER = inout/
IN_OUT_FILES = lines.c print.c write.c
IN_OUT = $(addprefix $(IN_OUT_FOLDER), $(IN_OUT_FILES))

# ALL SOURCES TOGHETER
SRC = $(CHARACTER) $(STRING) $(MEMORY) $(CONVERT) $(IN_OUT) $(MATHS) $(DATA)
OBJ = $(SRC:.c=.o)

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE'S RULES             #
# *                                      * #
#==--------------------------------------==#

all: $(NAME)

.c.o:
	@gcc $(FLAGS) $(DEFINES) -o $@ -c $<

$(NAME): $(OBJ)
	@ar -rsc $(NAME) $(OBJ)
	@printf "\033[32mThe library LIBFT has been loaded!\033[0m\n"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: all
	@gcc $(DANGER) -L. -lft -o $(TEST_OUT) $(TEST_FILE)
	@./$(TEST_OUT)
	@rm -Rf $(TEST_OUT) $(TEST_OUT).dSYM

.PHONY: all clean fclean re test
