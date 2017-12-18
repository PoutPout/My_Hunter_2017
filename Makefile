##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRC     =       hunter.c                    \

NAME    =       my_hunter

$(NAME):
		gcc -o $(NAME) $(SRC) -L. lib/my/libmy.a -l c_graph_prog

all:		$(NAME)

clean:
		rm -f $(NAME)
fclean:		clean
		rm -f $(NAME)
re:	fclean all
