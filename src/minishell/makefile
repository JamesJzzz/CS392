NAME = minishell

SRC = minishell.c
OBJ = $(SRC:.c=.o)

CFLAGS = -I ../../include  -Wall -Werror --pedantic
LDFLAGS =

all: $(OBJ)
	cc -L../../lib $(OBJ) -o $(NAME) -lmy

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all