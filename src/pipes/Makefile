OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	gcc pipes.c -o pipes -Wall -Werror --pedantic -I../../include -L../../lib -lmy

clean:
	rm -f $(OBJ) pipes

re: clean all
