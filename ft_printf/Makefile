# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itsiros <itsiros@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:34:19 by itsiros           #+#    #+#              #
#    Updated: 2024/11/08 18:40:13 by itsiros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -o -I

NAME = libftprintf.a
SRCS = ft_printf.c unsigned_casting.c convert_to_hex.c \
		convert_pto_hex.c convert_to_caphex.c ft_conversions.c \
		ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c print_pointer_hex.c
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

# Rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove object files
clean:
	rm -f $(OBJS)

# Fclean target to remove the library and object files
fclean: clean
	rm -f $(NAME)

# Rebuild target to clean and then build again
re: fclean all

.PHONY: all clean fclean re