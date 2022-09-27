# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcollar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 14:58:25 by flcollar          #+#    #+#              #
#    Updated: 2022/03/30 14:31:57 by flcollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==--------------------------------------==#
# *                                      * #
#             GLOBAL SETTINGS              #
# *                                      * #
#==--------------------------------------==#

CLIENT = client
SERVER = server

FLAGS = -Wall -Werror -Wextra
DANGER = -fsanitize=address -g3

#==--------------------------------------==#
# *                                      * #
#             LISTING SOURCES              #
# *                                      * #
#==--------------------------------------==#

LIB_FOLDER = ./libft/
LIB_NAME = ft
LIB = -L $(LIB_FOLDER) -l $(LIB_NAME)

CLIENT = client
C_SRC = client.c
C_OBJ = $(C_SRC:.c=.o)

SERVER = server
S_SRC = server.c
S_OBJ = $(S_SRC:.c=.o)

#==--------------------------------------==#
# *                                      * #
#                   RULES                  #
# *                                      * #
#==--------------------------------------==#

all: dependency $(CLIENT) $(SERVER)

.c.o:
	@gcc $(FLAGS) -o $@ -c $<

dependency:
	@make -C $(LIB_FOLDER)

$(CLIENT): $(C_OBJ)
	@gcc $(DANGER) $(LIB) -o $(CLIENT) $(C_OBJ)

$(SERVER): $(S_OBJ)
	@gcc $(DANGER) $(LIB) -o $(SERVER) $(S_OBJ)

clean:
	@rm -f $(C_OBJ) $(S_OBJ)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)

aclean: fclean
	@make fclean -C $(LIB_FOLDER)

re: aclean all

.PHONY: all dependency clean fclean aclean re