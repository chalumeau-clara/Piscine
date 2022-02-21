CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -g -pedantic -fsanitize=address 

SRC = dlist/dlist.c
OBJ = dlist/dlist.o
BIN = dlist/dlist
LIB = libdlist.a

all: library check

library: $(LIB)

$(LIB): $(OBJ)
	ar csr $(LIB) $(OBJ)

check: $(BIN)
	./$(BIN)


clean:
	$(RM) $(OBJ) $(BIN) $(LIB)

