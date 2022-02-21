CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic -g

SRC = gtree.c print.c serialize.c
OBJ = gtree.o print.o serialize.o
BIN = main 
LIB = libgtree.a

all: library

library: $(LIB)

$(LIB): $(OBJ)
	ar csr $(LIB) $(OBJ)

check: $(BIN)
	./$(BIN)

clean:
	$(RM) $(OBJ) $(BIN) $(LIB)
