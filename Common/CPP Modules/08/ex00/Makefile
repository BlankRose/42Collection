# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   CPP Modules - Makefile                          #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Fri Jun  3 21:08:23 CEST 2022     #
#      ||  '-'                                                          #
# ********************************************************************* #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

# Executable's name
NAME = find

# Compilation options
COMPILER = c++
LIBRARIES = 
FLAGS = -Wall -Werror -Wextra -g3 -std=c++98
ifneq ($(OS), Windows_NT)
	DANGER = -fsanitize=address
endif

# Success message to be displayed when compilation is complete
SUCCESS_MSG = The programm $(NAME) has been compiled successfully!

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

FONCTIONS = main.cpp
CLASSES = 

SRC = $(CLASSES) $(FONCTIONS)
OBJ = $(SRC:.cpp=.o)

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE'S RULES             #
# *                                      * #
#==--------------------------------------==#

# Main call upon 'make'
all: $(NAME)

# Compile the sources into object files
.cpp.o:
	@$(COMPILER) $(LIBRARIES) $(FLAGS) -o $@ -c $<

# Compile the dependencies using their Makefiles
dependency:
ifdef EXTERNAL_FOLDER
	@make -sC $(EXTERNAL_FOLDER)
endif

# Compile the objects and dependencies into an executable
$(NAME): dependency $(OBJ)
	@$(COMPILER) $(DANGER) -o $(NAME) $(OBJ) $(EXTERNAL)
ifneq ($(OS), Windows_NT)
	@printf "\033[32m$(SUCCESS_MSG)\033[0m\n"
else
	@echo $(SUCCESS_MSG)
endif

# Clears all objects files
clean:
ifeq ($(OS), Windows_NT)
	@del /F /Q $(subst /,\,$(OBJ))
else
	@rm -f $(OBJ)
endif

# Clears all objects files, INCLUDING the executable
fclean: clean
ifeq ($(OS), Windows_NT)
	@del /F /Q $(addsuffix .exe, $(subst /,\,$(NAME)))
else
	@rm -f $(NAME)
endif

# Cleans the External libs folder using their Makefiles
libclean:
ifdef EXTERNAL_FOLDER
	@make fclean -sC $(EXTERNAL_FOLDER)
endif

# Clears and recompile the whole project
re: fclean all

# Does a quick compile to test run then clears everything
test: all
	@./$(NAME)
	@make fclean

# Protection
.PHONY: all dependency clean fclean libclean re test