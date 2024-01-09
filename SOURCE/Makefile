##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Makefile
##

SRC	=	main.c		\
		play_music.c	\
		display_game.c	\
		initiation.c	\
		lib/strlen.c	\
		displaylife.c	\
		event.c	\
		bird_gestion.c	\
		level_gestion.c	\
		display_menu.c	\
		initiation_bird.c	\
		lib/my_getnbr.c	\
		lib/my_strdup.c	\
		lib/my_strcpy.c	\
		sort_score.c	\
		scoreboard_gestion.c	\
		help.c	\

OBJ	=	${SRC:.c=.o}
NAME	=	my_hunter

FLAGS	=	-l csfml-graphics -l csfml-audio -l csfml-system -l csfml-window

all: ${NAME}

$(NAME):
	gcc -o$(NAME) $(SRC) $(FLAGS)

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
