CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -g -pedantic -fsanitize=address -D_XOPEN_SOURCE=700

SRC = csv.c
OBJ = csv.o
BIN = csv

all: $(BIN)

clean:
	$(RM) $(OBJ) $(BIN)
