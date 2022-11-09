# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   CPP Module 04 - Makefile                        #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Tue Nov  8 19:02:21 CET 2022      #
#      ||  '-'                                                          #
# ********************************************************************* #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

NAME = magic
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
DANGER = -fsanitize=address
COMPILER = c++

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

FONCTIONS = main.cpp
CLASSES = Character.cpp AMateria.cpp Ice.cpp Cure.cpp MateriaSource.cpp

SRC = $(CLASSES) $(FONCTIONS)
OBJ = $(SRC:.cpp=.o)

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE'S RULES             #
# *                                      * #
#==--------------------------------------==#

a: all
all: $(NAME)

.cpp.o:
	@$(COMPILER) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@$(COMPILER) $(DANGER) $(OBJ) -o $(NAME)
	@printf "\033[32mThe programm $(NAME) has been compiled successfully!\033[0m\n"

c: clean
clean:
	@rm -f $(OBJ)

fc: fclean
fclean: clean
	@rm -f $(NAME)

re: remake
remake: fclean all

r: run
run: all
	@./$(NAME)
	@make fclean

.PHONY: all clean fclean remake run