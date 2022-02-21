CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic -g -lcriterion
LDFLAGS+=-lcriterion
SRC = src/tinyprintf.c tests/test.c
OBJ = src/tinyprintf.o tests/test.o
BIN = tests/test
all: $(BIN)

check:
	./$(BIN)

$(BIN): $(OBJ)

$(OBJ): $(SRC)

clean:
	$(RM) $(OBJ) $(BIN)

