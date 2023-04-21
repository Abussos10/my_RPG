##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

NAME	=	my_rpg

RM		=	rm -rf

SRC		=	./src/main.c					\
			./src/map/init_map.c			\
			./src/init_sprites.c			\
			./src/perso/players_movements.c	\
			./src/menu/menu.c 				\
			./src/menu/init_sprite.c		\
			./src/menu/init_music.c			\
			./src/menu/draw.c 				\
			./src/menu/button.c 			\

OBJ		=	$(SRC:.c=.o)

GCC		=	gcc

CFLAGS	= 	-I ./include

CERROR	=	-W -Wextra

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm -g -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GCC) $(CFLAGS) $(CERROR) $(SRC) -o $(NAME) $(CSFML)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re