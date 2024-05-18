
NAME 		= 	game

SRC 		= 	src/main.cpp \
				src/Core/Core.cpp \
				src/Pieces/Pieces.cpp \
				src/Menu/Menu.cpp \
				src/Player/Player.cpp \

CPPFLAGS	=   -iquote ./include

SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

CFLAGS 	=	-std=c++20 -Wall -Wextra -Werror

CFLAGS 		=	-Wall -Wextra -Werror -std=c++20 -fno-gnu-unique

OBJ 		=	$(SRC:.cpp=.o)

CC			=	g++


all: $(NAME)

$(NAME): $(OBJ)
<<<<<<< Updated upstream
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system
=======
	$(CC) -o $(NAME) $(CFLAGS) $(SFMLFLAGS) $(OBJ)
>>>>>>> Stashed changes

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

debug: $(CFLAGS) += -g3
debug: re

re: fclean all

.PHONY: all clean fclean debug re
