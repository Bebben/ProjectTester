##
## Makefile for projtester in /home/benoit.pingris/delivery/github_perso/projTest
## 
## Made by benoit pingris
## Login   <benoit.pingris@epitech.net>
## 
## Started on  Tue Jun 20 20:38:13 2017 benoit pingris
## Last update Tue Jun 20 20:38:18 2017 benoit pingris
##

CC	=	gcc

NAME	=	projTester

SRC	=	src/main.c	\

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

