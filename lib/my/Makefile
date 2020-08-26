##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compiles BSQ's lib
##

SRC	= 	map.c	\
		my_getnbr.c	\
		my_putchar_list.c	\
		my_put_nbr_list.c	\
		my_putstrlist.c	\
		my_printf.c	\
		my_printf_put_str.c	\
		dec_to_oct.c	\
		player.c	\
		my_putstr.c

NAME	= 	libmy.a

OBJ	= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)
	rm -rf *~
	rm -rf *#
	rm -rf include/*~

re: fclean all

.PHONY: all clean fclean re
