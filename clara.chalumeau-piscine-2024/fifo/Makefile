CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -g -pedantic -fsanitize=address 

SRC = fifo/fifo.c
OBJ = fifo/fifo.o
BIN = fifo/fifo
LIB = libfifo.a

all: library check

library: $(LIB)

$(LIB): $(OBJ)
	ar csr $(LIB) $(OBJ)

check: $(BIN)
	./$(BIN)


clean:
	$(RM) $(OBJ) $(BIN) $(LIB)

