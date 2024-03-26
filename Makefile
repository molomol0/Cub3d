# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francesco <francesco@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 18:05:44 by jdenis            #+#    #+#              #
#    Updated: 2024/03/26 10:27:12 by francesco        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

MLX_PATH	= minilibx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LDFLAGS = $(LIBFT) $(MLX) -lreadline

CPPFLAGS = 	-I libft/								\
			-I includes/							\
			-I src/									\
			-I minilibx/							\

OBJS =		$(addprefix src/,						\
			main.o									\
			read_file.o								\
			check_arg.o 							\
			map.o									\
			map_utils.o								\
			data.o									\
			widow.o									\
			key_event.o								\
			flood_fill.o							\
			clone_tab.o								\
			init_player.o							\
			raycasting.o							\
			get_texture.o							\
			minimap.o								\
			map_check.o								\
													\
			$(addprefix rendering/,					\
			put_wall.o						))
			
NAME = Cub3d
LIBFT = libft/libft.a
LIBFTPATH = libft/

all: $(MLX) $(LIBFT) $(NAME)

$(LIBFT):
	@ $(MAKE) -C $(LIBFTPATH) --no-print-directory > /dev/null 2>&1 && echo "Libft \033[1;32mOK\033[m"

$(MLX):
	@ make -sC $(MLX_PATH) --no-print-directory > /dev/null 2>&1 && echo "MiniLibX \033[1;32mOK\033[m"

libft: $(LIBFT)

$(NAME): $(OBJS)
	@ $(MAKE) -C $(LIBFTPATH) > /dev/null 2>&1
	@ $(CC) $(CFLAGS) -o $(NAME) $(MLX) $^ $(LDFLAGS) -lXext -lX11 -lm  > /dev/null 2>&1 
	@ echo "Compilation of  $(NAME):  \033[1;32mOK\033[m"

clean:
	@ $(RM) $(OBJS) > /dev/null 2>&1
	@ $(MAKE) clean -C $(LIBFTPATH) > /dev/null 2>&1
	@ $(MAKE) clean -C $(MLX_PATH) > /dev/null 2>&1
	@ echo "\033[1;33m>> all .o files are deleted.\033[0m"

fclean: clean
	@ $(RM) $(NAME) > /dev/null 2>&1
	@ $(MAKE) fclean -C $(LIBFTPATH) > /dev/null 2>&1
	@ $(RM) libtest.so > /dev/null 2>&1
	@echo "\033[0;31m>> $(NAME) all objects are deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re libft
