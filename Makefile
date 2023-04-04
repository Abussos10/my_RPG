##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

NAME	=	my_rpg

RM		=	rm -rf

SRC		=	./src/main.c			\
			./src/lib_functions.c 	\
			./src/init_map.c		\
			./src/init_sprites.c

OBJ		=	$(SRC:.c=.o)

GCC		=	gcc

CFLAGS	= 	-I ./include

CERROR	=	-W -Wextra -Werror

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GCC) $(CFLAGS) $(CERROR) $(SRC) -o $(NAME) $(CSFML)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re