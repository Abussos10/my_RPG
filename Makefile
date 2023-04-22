##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

NAME	=	my_rpg

RM		=	rm -rf

SRC		=	./src/main.c										\
			./src/map/init_map.c								\
			./src/map/map_borders.c								\
			./src/initialization/init_struct.c					\
			./src/initialization/init_sprites.c					\
			./src/initialization/init_tools.c					\
			./src/character/player_movements.c					\
			./src/character/player_collisions.c 				\
			./src/character/init_sprite_perso.c 				\
			./src/character/animation.c							\
     		./src/menu/main_menu/menu.c 						\
			./src/menu/main_menu/init_sprite.c					\
			./src/menu/main_menu/init_music.c					\
			./src/menu/main_menu/draw.c 						\
			./src/menu/main_menu/button.c						\
			./src/inventaire/inventaire.c						\
			./src/health_bar/health_bar.c
#			./src/menu/game_menu/game_menu.c					
#			./src/menu/game_menu/game_menu_sprites.c    		
#			./src/menu/game_menu/game_menu_window.c	    		
#			./src/menu/game_menu/hitbox_tools.c					

OBJ		=	$(SRC:.c=.o)

GCC		=	gcc

CFLAGS	= 	-I ./include -lm -g -Wall -Wextra

CERROR	=	-W -Wextra

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

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
