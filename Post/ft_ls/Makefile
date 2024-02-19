# ############################################################################ #
#          .-.                                                                 #
#    __   /   \   __                                                           #
#   (  `'.\   /.'`  )  Makefile                                                #
#    '-._.(;;;)._.-'                                                           #
#    .-'  ,`"`,  '-.                                                           #
#   (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)                #
#       //\   /        Last Updated: February 15, 2024 [09:50 am]              #
#      ||  '-'                                                                 #
# ############################################################################ #


#  CONFIGURATION
# ########################## #

NAME    := ft_ls
FILES   := utils/compare utils/math utils/output utils/directory\
            core/init core/options core/unfold core/stat core/sort\
            core/output core/result main

OBJECTS := $(foreach i, $(FILES), obj/$(i).o)
CFLAGS  := -Wall -Wextra -Wpedantic -Wunreachable-code\
            -Wunreachable-code-aggressive -Werror\
            -g3 -Iinclude
LDFLAGS := -fsanitize=address -O3


#  RULES
# ########################## #

$(NAME): $(OBJECTS)
	$(CC) $^ -o $@ -lacl

debug: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@ -lacl

obj/%.o: src/%.c | $(wildcard include/*.h)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) -R obj

fclean: clean
	$(RM) $(NAME) debug

info:
	@echo "TARGETS: " $(FILES)
	@echo "INCLUDES:" $(wildcard include/*.h)
	@echo -n "LIBC:     "
	nm -u $(NAME) | grep -v '__'

symbols:
	nm -ul $(OBJECTS)

.PHONY: all debug clean fclean remake info symbols
.DEFAULT_GOAL := $(NAME)



#  SHORTCUTS
# ########################## #

all: $(NAME) debug
remake: fclean $(NAME)

a: all
d: debug
c: clean
fc: fclean
re: remake
i: info
s: symbols
