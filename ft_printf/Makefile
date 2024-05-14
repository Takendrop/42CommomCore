# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 20:34:48 by jwozniak          #+#    #+#              #
#    Updated: 2024/03/05 20:34:50 by jwozniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS := src/ft_printf.c src/ft_print_x.c src/ft_print_id.c \
	src/ft_print_p.c src/ft_print_s.c src/ft_print_u.c \
	src/ft_putchar.c src/ft_putstr.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
