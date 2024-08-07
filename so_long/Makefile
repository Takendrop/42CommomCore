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

CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
RM		=	rm -rf
LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
MLX_DIR		=	./mlx_linux
MLX_LIB		=	$(MLX_DIR)/libmlx.a
SRCS		=	src/main.c src/init.c src/parsing.c src/checks.c src/map.c src/draw.c src/hook.c \
			src/player.c src/utils.c src/cleanup.c src/sprites.c src/error.c
OBJ		=	$(SRCS:.c=.o)
LDFLAGS		=	-L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES	=	-I$(LIBFT_DIR) -I$(MLX_DIR)

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
