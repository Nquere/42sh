#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/28 21:49:33 by luccasim          #+#    #+#              #
#    Updated: 2014/06/23 18:35:11 by jalula           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		=	llvm-gcc $(CFLAGS)

CFLAGS	=	-Wall -Werror -Wextra -g

SRC		=	mem/ft_memcpy.c \
			mem/ft_memset.c \
			mem/ft_bzero.c \
			mem/ft_memcpy.c \
			mem/ft_memmove.c \
			mem/ft_memchr.c \
			mem/ft_memcmp.c \
			string/ft_strlen.c \
			string/ft_strdup.c \
			string/ft_strcpy.c \
			string/ft_strncpy.c \
			string/ft_strcat.c \
			string/ft_strncat.c \
			string/ft_strlcat.c \
			string/ft_strchr.c \
			string/ft_strrchr.c \
			string/ft_strstr.c \
			string/ft_strnstr.c \
			string/ft_strcmp.c \
			string/ft_strncmp.c \
			string/ft_replace.c \
			string/ft_atoi.c \
			string/ft_implode.c \
			bool/ft_isdigit.c \
			bool/ft_isalpha.c \
			bool/ft_isalnum.c \
			string/ft_toupper.c \
			string/ft_tolower.c \
			mem/ft_memalloc.c \
			mem/ft_memdel.c \
			string/ft_strnew.c \
			string/ft_strdel.c \
			string/ft_strclr.c \
			string/ft_striter.c \
			string/ft_striteri.c \
			string/ft_strequ.c \
			string/ft_strnequ.c \
			string/ft_strsub.c \
			string/ft_strjoin.c \
			string/ft_strtrim.c \
			string/ft_strtrim_c.c \
			string/ft_strsplit.c \
			string/ft_destroysplit.c \
			string/ft_tablen.c \
			string/ft_sstrdup.c \
			string/ft_itoa.c \
			stdio/ft_putstr.c \
			stdio/ft_putendl.c \
			stdio/ft_putnbr.c \
			stdio/ft_putchar.c \
			stdio/ft_putstr_fd.c \
			stdio/ft_putendl_fd.c \
			stdio/ft_putnbr_fd.c \
			stdio/ft_putchar_fd.c \
			stdio/ft_error.c \
			stdio/ft_fatal_error.c \
			stdio/get_next_line.c \
			stdio/ft_puttab.c \
			avl/ft_avlbalancing.c \
			avl/ft_avlheight.c \
			avl/ft_avlinsert.c \
			avl/ft_avlnew.c \
			avl/ft_avlrotleft.c \
			avl/ft_avlrotright.c \
			avl/ft_avlsetheight.c \
			avl/ft_avlinfix.c \
			avl/ft_avlprefix.c \
			avl/ft_avlpostfix.c \
			tree/ft_treenew.c \
			tree/ft_treeadd.c \
			tree/ft_treeinfix.c \
			tree/ft_treesufix.c \
			tree/ft_treeprefix.c \
			tree/ft_treeput.c \
			tree/ft_treeputrev.c \
			tree/ft_treedestroy.c \
			tree/ft_treedel.c \
			tree/ft_listtotree.c \
			tree/ft_treesize.c \
			list/ft_listnew.c \
			list/ft_listaddhead.c \
			list/ft_listaddtail.c \
			list/ft_listdestroy.c \
			list/ft_listput.c \
			list/ft_listsize.c \
			list/ft_parse_option.c \
			ldc/ft_ldcnew.c \
			ldc/ft_ldcroot.c \
			ldc/ft_ldcaddnext.c \
			ldc/ft_ldcaddprev.c \
			ldc/ft_ldcputnext.c \
			ldc/ft_ldcputprev.c \
			ldc/ft_ldcdel.c \
			ldc/ft_ldcdestroy.c \
			ldc/ft_ldcnext.c \
			ldc/ft_ldcprev.c \
			ldc/ft_ldcput.c \
			unix/ft_getenv.c \
			unix/ft_file_exist.c \
			unix/ft_test_file.c \
			unix/ft_test_cmd.c \
			unix/ft_execve.c \
			unix/ft_redir.c \
			unix/ft_pipe.c \


NAME	=	libft.a

DINC = includes/
DSRC = srcs/
DOBJ = objs/

D1 = avl/
D2 = bool/
D3 = ldc/
D4 = list/
D5 = mem/
D6 = stdio/
D7 = string/
D8 = tree/
D9 = unix/

RMF = /bin/rm -f
RMD = /bin/rm -Rf
MKD = /bin/mkdir -p

OBJ = $(patsubst %.c, $(DOBJ)%.o, $(SRC))

all: $(NAME)

x:
	$(CC) test.c -L. -lft

$(DOBJ)%.o: $(DSRC)%.c
	@$(MKD) $(DOBJ)
	@$(MKD) $(DOBJ)/$(D1)
	@$(MKD) $(DOBJ)/$(D2)
	@$(MKD) $(DOBJ)/$(D3)
	@$(MKD) $(DOBJ)/$(D4)
	@$(MKD) $(DOBJ)/$(D5)
	@$(MKD) $(DOBJ)/$(D6)
	@$(MKD) $(DOBJ)/$(D7)
	@$(MKD) $(DOBJ)/$(D8)
	@$(MKD) $(DOBJ)/$(D9)
	@$(CC) -o $@ -c $< -I $(DINC)

$(NAME): $(OBJ)
	@echo "Creation de la libft."
	ar rcs $(NAME) $(OBJ)

clean:
	$(RMF) $(OBJ)
	@$(RMD) $(DOBJ)

fclean: clean
	$(RMF) $(NAME)

re: fclean all

norme:
	norminette srcs/avl/* ;
	norminette srcs/bool/* ;
	norminette srcs/list/* ;
	norminette srcs/ldc/* ;
	norminette srcs/mem/* ;
	norminette srcs/stdio/* ;
	norminette srcs/string/* ;
	norminette srcs/tree/* ;
	norminette srcs/unix/* ;
	norminette includes/* ;

.PHONY: all clean fclean re
