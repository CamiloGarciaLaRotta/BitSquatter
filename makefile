all:	bitsquat 

bitsquat: regexer.o main.c header.h
	gcc -Wall regexer.o main.c -o bitsquat

regexer.o: regexer.c
	gcc -Wall -c regexer.c
 
clean: 
	rm *.o bitsquat

gg: clean all
