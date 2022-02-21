CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -g -pedantic -fsanitize=address 

SRC = dlist_advanced/dlist_advanced.c dlist_advanced/dlist.c
OBJ = dlist_advanced/dlist_advanced.o dlist_advanced/dlist.o
BIN = dlist_advanced/dlist_advanced
LIB = libdlist.a

all: library

library: $(LIB)

$(LIB): $(OBJ)
	ar csr $(LIB) $(OBJ)

clean:
	$(RM) $(OBJ) $(BIN) $(LIB)

