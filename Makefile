#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/13 16:17:57 by luccasim          #+#    #+#              #
#    Updated: 2014/06/10 22:26:42 by luccasim         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		=	llvm-gcc
SRC		=	$(wildcard srcs/*.c)
OBJ		=	$(SRC:.c=.o)
LIB		=	-L libft/ -lft
INC		=	-I includes
CFLAGS	=	-Wall -Werror -Wextra $(INC)
NAME	=	42sh

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(CFLAGS) $(LIB) $(OBJ)

clean:
	make -C libft/ clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -rf $(NAME)

n:
	norminette srcs/*.c
	norminette includes/*.h

norme: n
	make -C libft/ norme

re: fclean all

.PHONY: all clean fclean re n norme