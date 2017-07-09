#include "header.h"

// General TODOs
//	- Add error handling for CL arguments
//	- Add -h --help
//	- Allow all possible urls
// 	- Remove preceding http(s):// and www. from url


// fill an array with the binary representation of a character
void get_binary(int ch, int position, char arr[])
{
        int remainder;
        while(ch > 0)
        {
                remainder = ch % 2;
                ch /= 2;
                arr[position--] = remainder + '0'; // int -> char
        }
}

// return the bitstring representation of a string
void get_bitstring(const char* str, char bitstring[])
{
        int i;    // string index
        int Byte; // character index in bitstring
        for(i=0, Byte=7;i<strlen(str);i++,Byte+=8)
        {
                get_binary(str[i], Byte, bitstring);
        }
}

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
	
	char dom_base_bitstring[dom_length*8];
	char ext_base_bitstring[ext_length*8];
	
	// initialize string to "0"
        // this will be helpful when filling the bitstring with the bin representation of a char
        memset(dom_base_bitstring, '0', (int)dom_length*8);
        memset(ext_base_bitstring, '0', (int)ext_length*8);
	
	get_bitstring(dom, dom_base_bitstring);
	get_bitstring(ext, ext_base_bitstring);
	
	printf("%.*s\n", (int)dom_length*8, dom_base_bitstring);
	printf("%.*s\n", (int)ext_length*8, ext_base_bitstring);

	free(dom);
	free(ext);
	
	return(EXIT_SUCCESS);
}
