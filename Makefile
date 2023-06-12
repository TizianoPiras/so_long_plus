# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:09:36 by tpiras            #+#    #+#              #
#    Updated: 2023/06/11 16:39:09 by ertiz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBX_PATH = ./mlx

MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

NAME = so_long

HEADER = $(NAME:.a=.h)

SOURCES = so_long.c \
		map.c \
		game.c \
		control.c \
		graphic_UI.c \
		movement.c \
		enemy_movement.c \
		death_animation.c \
		door_animation.c \
		libft/ft_split.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		libft/ft_itoa.c \

OBJ = $(SOURCES:.c=.o)

LIBC = ar rcs

MLX = ./libmlx.dylib

CC = clang

RM = rm -f

MAKEFLAGS += --silent

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJ) $(LIBFT) $(MINILIBX) -L./libft/ -lft -L./mlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Imlx_linux -c -O3 $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MINILIBX):
	make -C $(MINILIBX_PATH)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MINILIBX_PATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(MINILIBX)

re: fclean all

.PHONY: all clean fclean re