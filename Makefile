CFLAGS=-Wall

all: bitsquat 

bitsquat: regexer.o bitsquat.o main.c 
	gcc $(CFLAGS) regexer.o bitsquat.o main.c -o bitsquat

regexer.o: regexer.c regexer.h
	gcc $(CFLAGS) -c regexer.c

bitsquat.o: bitsquat.c bitsquat.h
	gcc $(CFLAGS) -c bitsquat.c
 
clean: 
	rm *.o bitsquat

.PHONY: all clean

