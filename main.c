#include "header.h"

// General TODOs
//	- Add error handling for CL arguments
//	- Add -h --help
//	- Allow all possible urls
// 	- Remove preceding http(s):// and www. from url

// split url into domain name and domain extension
void split_url(const char* url, char* dom, char* ext)
{
	int start, end;
	
	match_regex("^[[:alnum:]]*(.)[[:alnum:].]*", url, &start, &end);	
	
	sprintf(dom, "%.*s", (start), url);
	sprintf(ext, "%.*s", (int)strlen(url)-end, url+start+1);
	
	/*	
	printf("Input string: %s\n", url);
	printf("Domain: %s\n", dom);
	printf("Extension: %s\n", ext);
	printf("Indices g: %d, %d\n", start, end);
	*/
}

/*
// transform characters of a string into corresponding Bytes 
void get_bitstring(const char* str, int bitstring[])
{
	int i;
	int Byte = 0
	for(i=0;i<strlen(str)-1;i++)
	{
		get_binary(str[i], arr[Byte]); //TODO find way of filling 8 cells of array in for loop 
		Byte+=8;
	}
}


// fill 8 cells with the binary representation of a character
void get_binary(int i, int arr[])
{
	int magnitude= 7;
	int remainder;
	while(i > 0)
	{
		remainder = i % 2;
		i /= 2;
		arr[magnitude--] = remainder;
	}
}
*/


int main(int argc, char* argv[])
{
	char* url = argv[argc-1];
	char* dom;
	char* ext;
	dom = (char*)malloc(BUFFER_SIZE*sizeof(char));
	ext = (char*)malloc(BUFFER_SIZE*sizeof(char));

	// get domain name + domain extension
	split_url(url, dom, ext);	
	
	// get bitstrings of domain/extension
	size_t dom_length = strlen(dom);
	size_t ext_length = strlen(ext);

	printf("Domain length: %zd\n", dom_length);
	printf("Extension length: %zd\n", ext_length);
	
//	int dom_bitstring[dom_length*8];
//	int ext_bitstring[ext_length*8];
	
//	get_bitstring(dom, dom_bitstring);
//	get_bitstring(ext, ext_bitstring);
	
	free(dom);
	free(ext);
	
	return(EXIT_SUCCESS);
}
