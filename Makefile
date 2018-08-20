# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/29 18:33:29 by mhedeon           #+#    #+#              #
#    Updated: 2018/08/20 21:06:25 by mhedeon          ###   ########.fr        #
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
	@echo "\t\033[33mCompiling Libft...\033[0;2m"
	@make -C libft
	@echo "\033[0;32mDone\033[0m"
	@echo "\t\033[33mCompiling MinilibX...\033[0;2m"
	@make -C minilibx
	@echo "\033[0;32mDone\033[0m"
	@echo "\t\033[33mCompiling Fract'ol project...\033[0;2m"
	gcc $(FLAGS) -c $(SRC)
	gcc -g -o $(NAME) $(OBJ) -L ./libft -lft -L ./minilibx -lmlx -framework OpenGL -framework AppKit
	@echo "\033[0;32mDone\033[0m"
	@echo "\033[30;42mCompilation completed\033[0m"

%.o: %.c
	@gcc $(FLAGS) -c $< -I $@
	
clean:
	@echo "\t\033[31mCleaning Libft objects...\033[0;2m"
	@make -C libft clean
	@echo "\033[0;32mDone\033[0m"
	@echo "\t\033[31mCleaning MinilibX objects...\033[0;2m"
	@make -C minilibx clean
	@echo "\033[0;32mDone\033[0m"
	@echo "\t\033[31mCleaning Fract'ol objects...\033[0;2m"
	rm -f $(OBJ)
	@echo "\033[0;32mDone\033[0m"
	@echo "\033[30;41mObject cleaning completed\033[0m"

fclean: clean
	@echo "\t\033[31mCleaning \033[1mlibft.a\033[0;31m file...\033[0;2m"
	rm -f libft/libft.a
	@echo "\033[0;32mDone\033[0m"
	@echo "\t\033[31mCleaning \033[1m$(NAME)\033[0;31m file...\033[0;2m"
	rm -f $(NAME)
	@echo "\033[0;32mDone\033[0m"
	@echo "\033[30;41mCompilation files cleaning completed\033[0m"

re: fclean all
