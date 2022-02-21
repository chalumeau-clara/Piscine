CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -g -pedantic -fsanitize=address 

SRC = vector.c
OBJ = vector.o
BIN = vector
LIB = libvector.a

all: library

library: $(LIB)

$(LIB): $(OBJ)
	ar csr $(LIB) $(OBJ)

check: $(BIN)
	./$(BIN)


clean:
	$(RM) $(OBJ) $(BIN) $(LIB)

