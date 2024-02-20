FLAGS	= -Wall -Werror -Wextra -g3
LINKS	= $(FLAGS) -fsanitize=address
ALL		= Colleen Grace Sully

#==--------------------------------------==#

a: all
all: $(ALL)

.c.o:
	$(CC) $(FLAGS) -o $@ -c $<

$(ALL): %: %.o
	$(CC) $(LINKS) -o $@ $<

c: clean
clean:
	$(RM) $(addsuffix .o, $(ALL)) out Grace_kid.c $(wildcard Sully_*)

fc: fclean
fclean: clean
	$(RM) $(ALL)

re: remake
remake: fclean all

#==--------------------------------------==#

.DEFAULT_GOAL = all
.PHONY: all clean fclean remake
