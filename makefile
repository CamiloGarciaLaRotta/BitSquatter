all: main

main: main.o
	gcc main.o -o bitsquat 

main.o: main.c
	gcc -c main.c

clean: 
	rm *.o bitsquat