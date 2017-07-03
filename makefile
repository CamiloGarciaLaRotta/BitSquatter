all: bitsquat 

bitsquat: main.c
	gcc -Wall -o bitsquat main.c

clean: 
	rm bitsquat
