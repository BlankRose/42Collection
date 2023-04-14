# ********************************************************************* #
#          .-.                                                          #
#    __   /   \   __                                                    #
#   (  `'.\   /.'`  )   LibASM - Makefile                               #
#    '-._.(;;;)._.-'                                                    #
#    .-'  ,`"`,  '-.                                                    #
#   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        #
#       //\   /         Last Updated: Thu Apr 13 18:32:38 CEST 2023     #
#      ||  '-'                                                          #
# ********************************************************************* #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

# Target Settings
NAME	= libasm.a
ARCH	= macho64
LIBS	= -lSystem # Requiered by MacOS for system calls and errno

# Utilities Sources
UTILS	= contains list_new
USRC	= $(foreach target, $(UTILS), src/utils/ft_$(target).s)
UOBJ	= $(USRC:.s=.o)

# Library Sources
LIBRARY	= write read strlen strcpy strdup strcmp
BONUS	= atoi_base list_push_front list_size list_sort list_remove_if
LSRC	= $(foreach target, $(LIBRARY) $(BONUS), src/ft_$(target).s) $(USRC)
LOBJ	= $(LSRC:.s=.o)

# Testing Sources
TESTING	= mandatory bonus main
TSRC	= $(foreach target, $(TESTING), test/$(target).c)
TOBJ	= $(TSRC:.c=.o)

# All Sources
ASRC	= $(LSRC) $(TSRC)
AOBJ	= $(LOBJ) $(TOBJ)

#==--------------------------------------==#
# *                                      * #
#              MAKEFILE RULES              #
# *                                      * #
#==--------------------------------------==#

a: all
all: $(NAME)

b: bonus
bonus: all

.s.o:
	@nasm -g -f $(ARCH) $<

.c.o:
	@gcc -g3 -c $< -o $@

$(NAME): $(LOBJ)
	@ar -rc $(NAME) $(LOBJ)

c: clean
clean:
	@rm -Rf $(AOBJ)

fc: fclean
fclean: clean
	@rm -Rf $(NAME) a.out

re: remake
remake: fclean all

t: test
test: $(AOBJ)
	@gcc $(AOBJ) $(LIBS) -fsanitize=address

r: run
run: test
	@./a.out "Nop"

#==--------------------------------------==#
# *                                      * #
#             MAKEFILE HANDLER             #
# *                                      * #
#==--------------------------------------==#

.DEFAULT_GOAL = all
.PHONY: all clean fclean remake test run