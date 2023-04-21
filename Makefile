##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

NAME	=	my_rpg

RM		=	rm -rf

SRC		=	./src/main.c				\
			./src/map/init_map.c			\
			./src/init_sprites.c		\
			./src/perso/players_movements.c	\
     		./src/menu/menu.c 				\
			./src/menu/init_sprite.c		\
			./src/menu/init_music.c			\
			./src/menu/draw.c 				\
			./src/menu/button.c

OBJ		=	$(SRC:.c=.o)

GCC		=	gcc

CFLAGS	= 	-I ./include

CERROR	=	-W -Wextra

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm -g -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo "\e[1;30mcompilation status:\e[0m" "\e[1;33m[ENGAGED] \e[0m"
	$(GCC) $(CFLAGS) $(CERROR) $(SRC) -o $(NAME) $(CSFML)
	@echo "\e[1;30mcompilation satuts: \e[0m" "\e[1;32m[OK] \e[0m"

clean:
	@echo "\e[1;30mclean status:\e[0m" "\e[1;33m[ENGAGED] \e[0m"
	$(RM) $(OBJ)
	@echo "\e[1;30mclean status:\e[0m" "\e[1;32m[OK] \e[0m"
fclean: clean
	$(RM) $(NAME)
	@echo "\e[1;30mfclean status:\e[0m" "\e[1;32m[OK] \e[0m"

re: fclean all

.PHONY: all clean fclean re