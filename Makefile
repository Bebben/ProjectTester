##
## Makefile for projtester in /home/benoit.pingris/delivery/github_perso/projTest
## 
## Made by benoit pingris
## Login   <benoit.pingris@epitech.net>
## 
## Started on  Tue Jun 20 20:38:13 2017 benoit pingris
## Last update Fri Jun 23 12:12:24 2017 benoit pingris
##

CC	=	gcc

NAME	=	projTester

SRC	=	src/main.c		\
		src/get_info.c		\
		src/tab.c		\
		src/my_exec.c		\
		src/parser.c		\
		src/recu.c		\
		src/tree.c		\
		src/disp.c		\
		src/find.c		\
		src/slash.c		\
		src/set.c		\
		src/gnl/gnl.c		\
		src/useful/epur_str.c	\
		src/useful/str_to_tab.c	\
		src/useful/putstr.c	\
		src/useful/sort.c	\
		src/useful/free.c	\
		src/useful/my_access.c	\
		src/useful/mallocat.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include -Wall -Wextra

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
