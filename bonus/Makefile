##
## EPITECH PROJECT, 2018
## 101pong
## File description:
## Compilation Makefile
##

SRC	=	match.c

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

LIB     =	lib/my/libmy.a

CFLAGS	=	-I include

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -g -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re:	fclean all

.PHONY: all clean fclean re
