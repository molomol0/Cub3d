# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 18:05:44 by jdenis            #+#    #+#              #
#    Updated: 2024/04/02 19:41:39 by jdenis           ###   ########.fr        #
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
			read_file_utils.o						\
			check_arg.o 							\
			map.o									\
			map_utils.o								\
			widow.o									\
			key_event.o								\
			key_check.o								\
			movement.o								\
			flood_fill.o							\
			clone_tab.o								\
			init_player.o							\
			raycasting.o							\
			raycasting_utils.o						\
			get_texture.o							\
			minimap.o								\
			ft_gettime.o							\
			map_check.o								\
			check_mouvement.o						\
			raycasting_fire.o						\
													\
			$(addprefix data/,						\
			data.o									\
			free_utils.o							\
			init_utils.o					)		\
													\
			$(addprefix rendering/,					\
			colors.o								\
			animation.o								\
			put_frame.o								\
			put_wall.o						))
			
NAME = Cub3d
NAME_BONUS = Cub3d_bonus
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

bonus: $(OBJS)
	@ $(MAKE) -C $(LIBFTPATH) > /dev/null 2>&1
	@ $(CC) $(CFLAGS) -o $(NAME_BONUS) $(MLX) $^ $(LDFLAGS) -lXext -lX11 -lm
	@ echo "Compilation of  $(NAME_BONUS):  \033[1;32mOK\033[m"

clean:
	@ $(RM) $(OBJS) > /dev/null 2>&1
	@ $(MAKE) clean -C $(LIBFTPATH) > /dev/null 2>&1
	@ $(MAKE) clean -C $(MLX_PATH) > /dev/null 2>&1
	@ echo "\033[1;33m>> all .o files are deleted.\033[0m"

fclean: clean
	@ $(RM) $(NAME) > /dev/null 2>&1
	@ $(RM) $(NAME_BONUS) > /dev/null 2>&1
	@ $(MAKE) fclean -C $(LIBFTPATH) > /dev/null 2>&1
	@ $(RM) libtest.so > /dev/null 2>&1
	@echo "\033[0;31m>> $(NAME) all objects are deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re libft
