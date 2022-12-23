# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 17:00:22 by wfan              #+#    #+#              #
#    Updated: 2022/12/23 17:09:33 by wfan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
SRC =  		get_next_line.c\
		get_next_line_utils.c\
		main.c
OBJ = $(SRC:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o $@

RM		    := rm -f


all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			@ $(RM) $(OBJ)

fclean:		clean
			@ $(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
