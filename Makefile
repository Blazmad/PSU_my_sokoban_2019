##
## EPITECH PROJECT, 2019
## CPool_bootstrap_evalexpr_2019
## File description:
## Makefile
##

SRC	=	main.c	\
		src/my_str_to_word_array.c	\
		src/open_file.c	\
		src/move_player.c	\
		src/win.c	\
		src/display_map.c	\
		lib/my/my_show_word_array.c	\
		lib/my/my_putchar.c	\
		lib/my/my_isneg.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_swap.c	\
		lib/my/my_strlen.c	\
		lib/my/my_putstr.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_compute_power_rec.c	\
		lib/my/my_compute_square_root.c	\
		lib/my/my_is_prime.c	\
		lib/my/my_find_prime_sup.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strncpy.c	\
		lib/my/my_revstr.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_strncmp.c	\
		lib/my/my_strupcase.c	\
		lib/my/my_strlowcase.c	\
		lib/my/my_strcapitalize.c	\
		lib/my/my_str_isalpha.c	\
		lib/my/my_str_isnum.c	\
		lib/my/my_str_islower.c	\
		lib/my/my_str_isupper.c	\
		lib/my/my_str_isprintable.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strstr.c	\
		lib/my/my_strncat.c	\

CC	=	gcc -W -Wall -Wextra -g3 -Os

CFLAGS	=	-I./include/

AR	=	ar rc

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

NAME2	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME2) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L. -lmy -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)

re:	fclean all