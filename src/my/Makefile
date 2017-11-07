

CC = gcc
FILES = *.c
OUT_EXE = libmy.a
CFLAGS = -Wall -Werror --pedantic -I../../include
OBJ = $(FILES:.c=.o)

all: $(FILES)
	$(CC) -c $(FILES) $(CFLAGS)
	ar -rc $(OUT_EXE) *.o
	ranlib $(OUT_EXE)
	mv $(OUT_EXE) ../../lib


clean:
	rm -f $(OBJ)

flcean:
	clean
	rm -f ../../lib/$(OUT_EXE)
re:
	flcean all
