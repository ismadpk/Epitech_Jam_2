
NAME 	= 	game

SRC 	= 	src/main.cpp \
			src/Core/Core.cpp \
			src/Medaille/Medaille.cpp \
			src/Menu/Menu.cpp \
			src/Player/Player.cpp \

CFLAGS 	=	-std=c++20 -Wall -Wextra -Werror

SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

OBJ 	=	$(SRC:.cpp=.o)

CC		=	g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(SFMLFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

debug: $(CFLAGS) += -g3
debug: re

re: fclean all

.PHONY: all clean fclean debug re
