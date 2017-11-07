CC = gcc
FILES = new_node.c add_node.c add_elem.c append.c add_node_at.c remove_node.c remove_last.c remove_node_at.c count_s_nodes.c print_string.c print_int.c print_char.c node_at.c elem_at.c traverse_string.c empty_list.c traverse_int.c traverse_char.c debug_int.c debug_string.c debug_char.c
OUT_EXE = libmylist.a
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
