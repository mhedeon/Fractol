# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/29 18:33:29 by mhedeon           #+#    #+#              #
#    Updated: 2018/08/20 16:51:15 by mhedeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Werror -Wextra

SRC = main.c init.c hooks.c rotate.c \
		draw.c hsv2rgb.c fract_mandelbrot.c \
		fract_julia.c fract_burnship.c \
		fract_blackhole.c fract_mushroom.c \
		fract_bocal.c fract_tricorn.c \
		fract_perpmand.c color1.c color2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C minilibx
	@gcc $(FLAGS) -c $(SRC)
	@gcc -g -o $(NAME) $(OBJ) -L ./libft -lft -L ./minilibx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@gcc $(FLAGS) -c $< -I $@
	
clean:
	@make -C libft clean
	@make -C minilibx clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean all
	@make -C libft re
	@make -C minilibx re