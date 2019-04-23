# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aspizhav <aspizhav@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 18:01:41 by aspizhav          #+#    #+#              #
#    Updated: 2019/01/30 17:39:34 by aspizhav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

SRC_PATH = src
SRC_NAME = main.c tools.c drawer.c creator.c coord_convert_to_complex.c\
		   preprogram.c sets.c other.c
OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang -O2
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/includes

LDFLAGS = -L libft
LDLIBS = -lft -lm -lmlx -framework OpenGL -framework AppKit #-O2

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\x1b[33;01mCompilation of Fractol:	\033[1;32mOK\033[m"
	@clear

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\x1b[33;01mFractol: \x1b[31;01mRemoving Objs\x1b[0m"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "\x1b[33;01mFractol : \x1b[31;01mRemoving Fractol\x1b[0m"

re: fclean all

.PHONY: all clean fclean re
