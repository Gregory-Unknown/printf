CC = gcc
NAME = libftprintf.a
DIR = srcs
INCLUDES = includes
MAKE = make
FLAGS = -Wall -Wextra -Werror
SRCS = $(DIR)/ft_printf.c \
			$(DIR)/ft_printf_utils.c \
			$(DIR)/ft_printf_utils2.c \
			$(DIR)/ft_print_char.c \
			$(DIR)/ft_print_string.c \
			$(DIR)/ft_string_utils.c \
			$(DIR)/ft_print_int.c \
			$(DIR)/ft_int_utils.c \
			$(DIR)/ft_int_utils2.c \
			$(DIR)/ft_print_hex.c \
			$(DIR)/ft_print_pointer.c \
			$(DIR)/ft_hex_utils.c \

HEAD = $(INCLUDES)/ft_printf.h
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re fclean clean
