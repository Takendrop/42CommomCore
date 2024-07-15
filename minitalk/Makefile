# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 16:23:52 by jwozniak          #+#    #+#              #
#    Updated: 2024/05/23 16:23:54 by jwozniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM		= rm -rf
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
SRCS		= client.c server.c
OBJ		= $(SRCS:.c=.o)

all:	$(LIBFT) client server

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

client: client.o $(LIBFT)
	$(CC) $(CFLAGS) -o client client.o $(LIBFT) -I$(LIBFT_DIR)

server: server.o $(LIBFT)
	$(CC) $(CFLAGS) -o server server.o $(LIBFT) -I$(LIBFT_DIR)

%.o:	%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) client server
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re
