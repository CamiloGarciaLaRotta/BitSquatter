#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print the contents of an int array
void printIntArray(int arr[])
{
	int i;
	// TODO to make it cleaner must find way to avoid hardcoding size of arr
	for(i=0;i<8;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}

// returns an 8-cell int array representing the input number
void getBinary(int i, int arr[])
{
	// we start stripping from LSB
	int magnitude = 7;
	int remainder;
	while(i>0)
	{	
		remainder = i%2;
		i /= 2;
		arr[magnitude--] = remainder; 
	}
}

// given an input string, fill an array with its corresponding Bytes 
void makeBitString(const char* str, int arr[])
{
	int i;
	int Byte = 0;
	for(i=0;i<strlen(str)-1;i++)
	{
		getBinary(str[i],arr[Byte++]);
	}
}	

int main(int argc, char* argv[])
{
	if(argc<2 ||(strcmp(argv[1],"-h")==0) || (strcmp(argv[1],"--help")==0))
	{
		printf("See man bitsquat\n");
	}
	// call makeBitString now, but must first make appropriate array based on size of URL	
	char ch = argv[1][0];
	// must initialize array to all zeroes
	int binaryChar[] = {0,0,0,0,0,0,0,0};
	getBinary(ch, binaryChar);
	printIntArray(binaryChar);		
	printf("%d", ch);	

	return EXIT_SUCCESS;
}
