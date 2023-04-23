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
			./src/sound/init_music.c							\
			./src/sound/sound_handler.c							\
			./src/character/player_movements.c					\
			./src/character/player_collisions.c 				\
			./src/character/init_sprite_perso.c 				\
			./src/character/animation.c							\
     		./src/menu/main_menu/menu.c 						\
			./src/menu/main_menu/init_sprite.c					\
			./src/menu/main_menu/init_music.c					\
			./src/menu/main_menu/draw.c 						\
			./src/menu/main_menu/button.c						\
			./src/events/events_handler.c 						\
			./src/events/health_pot_handler.c		 			\
			./src/events/sword_handler.c						\
			./src/inventory/inventory.c							\
			./src/health_bar/health_bar.c						\
			./src/npc/npc.c										\
			./src/enemy/init_enemy.c 							\
			./src/enemy/animation_bis.c							\
			./src/combat/fight.c								\
			./src/menu/loosewin/init_screen.c 					\
			./src/menu/loosewin/loop.c							\
			./src/menu/loosewin/button_end.c

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
