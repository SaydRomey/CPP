# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarrett <fbarrett@42quebec.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 09:59:24 by fbarrett          #+#    #+#              #
#    Updated: 2024/05/07 10:32:09 by fbarrett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RPN

MY_FILES	=	main.cpp RPN.cpp

CC			=	c++

CCFLAGS		=	-Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(O_DIRECT) $(MY_FILES)
	$(CC) $(CCFLAGS) -o $(NAME) $(MY_FILES)

weak:		
	$(CC) -o $(NAME) $(MY_FILES)

clean:
	rm -f *.o
	rm -rf *.dSYM
	
fclean:		clean
	rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re
