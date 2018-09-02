CFLAGS = -Wall -Wextra -ggdb3

all: bitsquat

bitsquat: regexer.o bitsquat.o main.c
	gcc $(CFLAGS) regexer.o bitsquat.o main.c -o bitsquat

regexer.o: regexer.c regexer.h
	gcc $(CFLAGS) -c regexer.c

bitsquat.o: bitsquat.c bitsquat.h
	gcc $(CFLAGS) -c bitsquat.c

test: clean bitsquat
	valgrind --leak-check=full \
			 --show-leak-kinds=all \
			 --track-origins=yes \
			 --verbose \
			 --log-file=valgrind-out.txt \
			 ./bitsquat -v toto.com

clean:
	rm *.o bitsquat

.PHONY: all clean test

