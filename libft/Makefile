CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = 			type/ft_isdigit.o				\
				type/ft_isalpha.o				\
				type/ft_isalnum.o				\
				type/ft_isascii.o				\
				type/ft_isprint.o				\
				string/ft_strchr.o					\
				string/ft_strlcat.o				\
				string/ft_strrchr.o				\
				type/ft_tolower.o				\
				type/ft_toupper.o				\
				string/ft_strncmp.o				\
				string/ft_strnstr.o				\
				mem/ft_memmove.o				\
				string/ft_strlen.o					\
				mem/ft_bzero.o					\
				mem/ft_memchr.o					\
				mem/ft_memset.o					\
				mem/ft_memcpy.o					\
				string/ft_strlcpy.o				\
				string/ft_strlcat.o				\
				mem/ft_memcmp.o					\
				conversion/ft_atoi.o					\
				mem/ft_calloc.o					\
				string/ft_substr.o					\
				string/ft_strjoin.o				\
				string/ft_strtrim.o				\
				string/ft_split.o					\
				conversion/ft_itoa.o					\
				string/ft_strmapi.o				\
				string/ft_striteri.o				\
				fd/ft_putchar_fd.o				\
				fd/ft_putstr_fd.o				\
				fd/ft_putendl_fd.o				\
				fd/ft_putnbr_fd.o				\
				string/ft_strdup.o					\
				string/ft_strs_to_ints.o			\
				ft_bubble_sort.o			\
				conversion/ft_swap.o					\
				string/ft_strslen.o				\
				string/ft_print_str.o				\
				string/ft_strcmp.o					\
				string/ft_find_paths.o				\
				mem/ft_free_strs.o				\
				string/ft_delete_newline.o			\
				mem/ft_realloc.o				\
				string/ft_strtok.o					\
				string/ft_strtok_utils.o			\
				string/ft_strtok_utils_2.o			\
				string/ft_strtok_utils_3.o			\
				string/ft_strtok_utils_4.o			\
				string/ft_strtok_utils_5.o			\
				string/ft_strsjoin.o				\
				string/ft_strbstr.o				\
				mem/ft_add_char.o				\
				gnl/get_next_line.o			\
				gnl/get_next_line_utils.o	\
				list/ft_lstnew.o					\
				list/ft_lstsize.o				\
				list/ft_lstlast.o				\
				list/ft_lstadd_back.o			\
				list/ft_lstdelone.o				\
				list/ft_lstclear.o				\
				list/ft_lstiter.o				\
				list/ft_lstmap.o					\
				list/ft_lstadd_front.o			\

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) src $@ $^
	ranlib $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
