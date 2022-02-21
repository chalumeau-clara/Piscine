CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic

hello_world: hello_world.o
	$(CC) -o hello_world hello_world.o
hello_world.o: hello_world.c
	$(CC) $(CFLAGS) -c -o hello_world.o hello_world.c
