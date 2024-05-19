
NAME 		= 	game

SRC 		= 	src/main.cpp \
				src/Core/Core.cpp \
				src/Pieces/Pieces.cpp \
				src/Menu/Menu.cpp \
				src/Player/Player.cpp \
				src/Parallaxe/Parallaxe.cpp\

CPPFLAGS	=   -iquote ./include

CFLAGS 		=	-Wall -Wextra -Werror -std=c++20 -fno-gnu-unique

OBJ 		=	$(SRC:.cpp=.o)

CC			=	g++


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

debug: $(CFLAGS) += -g3
debug: re

re: fclean all

.PHONY: all clean fclean debug re
