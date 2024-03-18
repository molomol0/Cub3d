# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 18:05:44 by jdenis            #+#    #+#              #
#    Updated: 2024/03/18 18:30:07 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLX_PATH	= minilibx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LDFLAGS = $(LIBFT) -lreadline

CPPFLAGS = 	-I libft/								\
			-I includes/							\

OBJS =		$(addprefix src/,						\
			main.o									\
			read_file.o								\
			check_arg.o 							\
			map.o									\
			map_utils.o								\
			data.o				)					\

NAME = Cub3d
LIBFT = libft/libft.a
LIBFTPATH = libft/

all: $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)

$(MLX):
	make -sC $(MLX_PATH)
	@echo "MiniLibX \033[1;32mOK\033[m"

libft: $(LIBFT)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPATH)
	$(CC) $(CFLAGS) -o $(NAME) $(MLX) $^ $(LDFLAGS) -lXext -lX11 -lm
	@echo "	Compilation of  $(NAME):  \033[1;32mOK\033[m"

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFTPATH)
	$(MAKE) clean -C $(MLX_PATH)
	@echo "\033[1;33m>> all .o files are deleted.\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFTPATH)
	$(RM) libtest.so
	@echo "\033[0;31m>> $(NAME) all objects are deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re libft
