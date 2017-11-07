CC = gcc
FILES = *.c
OUT_EXE = homework2
CFLAGS = -Wall -Werror --pedantic -I../../include
OBJ = $(FILES:.c=.o)

all: $(FILES)
	$(CC) $(CFLAGS) -c $(FILES)
	ar -rc libmy.a *.o
	ranlib libmy.a
	mv libmy.a ../../lib


clean:
	-$(RM) *.o

flcean:
	clean
	-$(RM) OUT_EXE

re:
	flcean all
