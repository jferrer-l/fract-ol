#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 16:35:11 by jferrer-          #+#    #+#              #
#    Updated: 2022/03/08 16:50:11 by jferrer-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME= frac.a

SRCS= calculate.c fractals.c hooks.c init_data.c utils.c

OBJ= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@echo "\033[36m"--Compilando--"\033[0m ";
	@make -sC ./minilibx_mms_20200219
	@make -sC ./minilibx_opengl_20191021
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	gcc -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -Wall -Werror -Wextra calculate.c utils.c hooks.c fractals.c init_data.c -o exec
	@clear

all: $(NAME)

re: fclean all

clean:
	@rm -rf $(NAME) $(OBJ) exec
	@make -sC ./minilibx_mms_20200219/ clean
	@make -sC ./minilibx_opengl_20191021/ clean
	@clear
	@echo "\033[34m"🗑️\  Todo depurado correctamente  \🗑️"\033[0m"

fclean: clean
		@rm -rf *.o

.PHONY: all clean re fclean
