
RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c pipex-utils.c pipex-utils2.c

BSRC = pipex-b.c pipex-utils.c pipex-utils2.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	$(RM) $(OBJ) $(BOBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

bonus: $(BOBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(BOBJ)	

.PHONY: all clean fclean re
