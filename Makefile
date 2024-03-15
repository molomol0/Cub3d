# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 18:05:44 by jdenis            #+#    #+#              #
#    Updated: 2024/03/15 18:12:33 by jdenis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = $(LIBFT) -lreadline

CPPFLAGS = 	-I libft/													\
			-I includes/												\

OBJS =		main.o

NAME = Cub3d
LIBFT = libft/libft.a
LIBFTPATH = libft/

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTPATH)

libft: $(LIBFT)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTPATH)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LDFLAGS)
	@echo "	Compilation of  $(NAME):  \033[1;32mOK\033[m"

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFTPATH)
	@echo "\033[1;33m>> all .o files are deleted.\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFTPATH)
	$(RM) libtest.so
	@echo "\033[0;31m>> $(NAME) all objects are deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re libft
