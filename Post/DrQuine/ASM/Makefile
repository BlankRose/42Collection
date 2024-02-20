ARCH	= elf64
LIBS	= -lc -dynamic-linker /usr/lib64/ld-linux-x86-64.so.2 # Requierds for linking against C library
ALL		= Colleen Grace Sully

#==--------------------------------------==#

#a: all
all: $(ALL)

.s.o:
	nasm -f $(ARCH) -o $@ $<

$(ALL): %: %.o
	ld $(LIBS) -o $@ $<

c: clean
clean:
	rm -rf $(addsuffix .o, $(ALL)) out Grace_kid.s $(wildcard Sully_*)

fc: fclean
fclean: clean
	rm -rf $(ALL)

re: remake
remake: fclean all

#==--------------------------------------==#

.DEFAULT_GOAL = all
.PHONY: all clean fclean remake
