CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic
LDFLAGS+=-lcriterion

SRC = src/evalexpr.c
OBJ = src/evalexpr.o
BIN = evalexpr

TESTSRC = tests/test.c
TESTOBJ = tests/test.o
TESTBIN = test

all: evalexpr

evalexpr: $(OBJ)
	gcc $(CFLAGS) -o $@ $(OBJ)

check: $(TESTBIN)
	./$(TESTBIN)

$(TESTBIN): $(OBJ) $(TESTOBJ)
	$(CC) $(CFLAGS) $(LDFALGS) -lcriterion -o $(TESTBIN)  $^

clean:
	$(RM) $(OBJ) $(BIN) $(TESTOBJ) $(TESTBIN)
