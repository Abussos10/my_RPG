##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## Makefile
##

NAME	=	my_rpg

RM		=	rm -rf

SRC		=	./src/main.c			\

OBJ		=	$(SRC:.c=.o)

GCC		=	gcc -c

CFLAGS	= 	-I./include

CERROR	=	-W -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GCC) $(CFLAGS) $(CERROR) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re