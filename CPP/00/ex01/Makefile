# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 20:14:42 by jwozniak          #+#    #+#              #
#    Updated: 2024/08/10 20:14:43 by jwozniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook
SRC		=	main.cpp PhoneBook.cpp Contact.cpp
OBJ		=	$(SRC:.cpp=.o)
CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) -o $@ $^

%.o:		%.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
