NAME = nsminishell

SRC = nsminishell.c
OBJ = $(SRC:.c=.o)

CFLAGS = -I ../../include  -Wall -Werror --pedantic
LDFLAGS =

all: $(OBJ)
	cc -L../../lib $(OBJ) -o $(NAME) -lmy -lmylist -lncurses -lmenu

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all