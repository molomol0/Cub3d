# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 18:05:44 by jdenis            #+#    #+#              #
#    Updated: 2024/03/19 18:00:00 by jdenis           ###   ########.fr        #
=======
#    By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 18:05:44 by jdenis            #+#    #+#              #
#    Updated: 2024/03/19 14:32:57 by ftholoza         ###   ########.fr        #
>>>>>>> a305efb0f9043d467c750795af3e78ba91ccadc1
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
<<<<<<< HEAD
			widow.o									\
			key_event.o								\
			map_check.o			)					\
=======
			map_check.o								\
			flood_fill.o		)					\
>>>>>>> a305efb0f9043d467c750795af3e78ba91ccadc1
			
NAME = Cub3d
LIBFT = libft/libft.a
LIBFTPATH = libft/

all: $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)

$(MLX):
	@make -sC $(MLX_PATH) --no-print-directory
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
