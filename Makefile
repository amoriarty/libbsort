# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 10:22:08 by alegent           #+#    #+#              #
#    Updated: 2017/05/18 16:15:25 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang -Wall -Wextra -Werror -g

NAME= libbsort.a

SRC_PATH= srcs/
SRC_NAME= bsort.c \
			floor_power_of_two.c \
			range.c \
			merge.c \
			rotate.c \
			insertion_sort.c

SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

INC= -I libft -I .
LIB= ./libft/libft.a

OBJ_PATH= obj/
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

main: $(NAME) main.o
	$(CC) $(INC) $(LIB) $(OBJ) main.o -o main

main.o: main.c
	$(CC) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@make -C libft
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) has been created."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)/
	$(CC) $(INC) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -rf $(NM_OBJ)
	@rm -rf $(NM_OBJ_PATH)
	@echo "Objects files are deleted."

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "$(NAME) are deleted."

re: fclean all

.PHONY: clean fclean re
