CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic -g -lcriterion
LDFLAGS+=-lcriterion

SRC = src/my_fnmatch.c
OBJ = src/my_fnmatch.o

TESTSRC = tests/test.c
TESTOBJ = tests/test.o

BIN = tests/test
LIB = libfnmatch.a

all: library check

library: $(LIB)

$(LIB): $(OBJ)
	ar csr $(LIB) $(OBJ)

check: $(BIN)
	./$(BIN)

$(BIN): $(OBJ) $(TESTOBJ)
	gcc -o $(BIN) -lcriterion $^

clean:
	$(RM) $(OBJ) $(BIN) $(LIB) $(TESTOBJ)
