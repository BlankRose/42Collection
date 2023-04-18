FLAGS	= -Wall -Werror -Wextra -g3
LINKS	= $(FLAGS) -fsanitize=address
ALL		= Colleen Grace Sully

#==--------------------------------------==#

a: all
all: $(ALL)

.c.o:
	gcc $(FLAGS) -o $@ -c $<

$(ALL): %: %.o
	gcc $(LINKS) -o $@ $<

c: clean
clean:
	rm -rf $(addsuffix .o, $(ALL)) out Grace_kid.c $(wildcard Sully_*)

fc: fclean
fclean: clean
	rm -rf $(ALL)

re: remake
remake: fclean all

#==--------------------------------------==#

.DEFAULT_GOAL = all
.PHONY: all clean fclean remake