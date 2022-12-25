# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 17:00:22 by wfan              #+#    #+#              #
#    Updated: 2022/12/25 16:44:00 by wfan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
NAMEBONUS = gnl_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
SRC =  		get_next_line.c\
		get_next_line_utils.c\
		main.c
SRCBONUS =       get_next_line_bonus.c\
                 get_next_line_utils_bonus.c\
		 main_bonus.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

RM		    := rm -f


all:		$(NAME) $(NAMEBONUS)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
$(NAMEBONUS):	$(OBJBONUS)
			$(CC) $(CFLAGS) $(OBJBONUS) -o $(NAMEBONUS)

clean:
			@ $(RM) $(OBJ) $(OBJBONUS)

fclean:		clean
			@ $(RM) $(NAME) $(NAMEBONUS)

re:			fclean all

.PHONY:		all clean fclean re
