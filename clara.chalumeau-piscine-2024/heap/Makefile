CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -g -pedantic -fsanitize=address 

SRC = create.c add.c pop.c del.c print.c
OBJ = create.o add.o pop.o del.o print.o
BIN = create
LIB = libheap.a

all: library check

library: $(LIB)

$(LIB): $(OBJ)
	ar csr $(LIB) $(OBJ)

check: $(BIN)
	./$(BIN)

$(BIN): $(OBJ)

$(OBJ): $(SRC)

clean:
	$(RM) $(OBJ) $(BIN) $(LIB)

