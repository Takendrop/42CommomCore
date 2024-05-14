# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 13:50:49 by jwozniak          #+#    #+#              #
#    Updated: 2024/04/19 13:50:51 by jwozniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
RM		= rm -rf
SRCS		= main.c node.c actions.c sort.c utils.c
SRC		= $(addprefix ./src/, $(SRCS))
OBJ		= $(SRC:.c=.o)

all:	$(LIBFT) $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJ):	$(SRC)
	@$(CC) $(CFLAGS) -c $^ -I$(LIBFT_DIR)
	@mv *.o src

clean:
	@$(RM) src/*.o
	@make -s -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re:	fclean all clean

.PHONY: all clean fclean re
