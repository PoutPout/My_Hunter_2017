##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRC     =       my_putchar.c                    \
                my_put_nbr.c                    \
                my_putstr.c                     \
                my_strlen.c                     \
		my_printf.c			\
		my_put_nbr_base.c 		\
		my_revstr.c

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

$(NAME):        $(OBJ)
		ar rc $(NAME) $(OBJ)

all:		$(NAME)

clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)
re:	fclean all
