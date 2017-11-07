SRC= myselect.c

OBJ=$(SRC:.c=.o)

CFLAGS = -L../../lib -I../../include -Wall -Werror --pedantic -g

all: $(OBJ)
	gcc $(CFLAGS) $(SRC) -o myselect -lmy -lncurses

clean:
	rm -f $(OBJ)
