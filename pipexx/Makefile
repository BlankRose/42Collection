
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = pipexcpy.c pipex-utils.c
OBJ = $(SRC:.c=.o)

NAME = libpipex.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rsc $(NAME) $(OBJ)
	@printf "\033[32mThe library PIPEX has been loaded!\033[0m\n"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean: 
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
