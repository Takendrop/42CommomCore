# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 12:28:19 by jwozniak          #+#    #+#              #
#    Updated: 2024/06/26 12:28:21 by jwozniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
RM		= rm -rf
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= ./mlx_linux
SRCS		= src/core/main.c src/core/init.c src/core/draw.c src/core/hook.c
OBJ		= $(SRCS:.c=.o)
LDFLAGS		= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES	= -I$(LIBFT_DIR) -I$(MLX_DIR)

all:	$(LIBFT) so_long

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

so_long: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o so_long $(OBJ) $(LIBFT) $(LDFLAGS)

%.o:	%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) so_long
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re
