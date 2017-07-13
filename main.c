#include "bitsquat.h"

#define BUFFER_SIZE 80

// General TODOs
//	- Add error handling for CL arguments
//	- Add -h --help
//	- Allow all possible urls
// 	- Remove preceding http(s):// and www. from url

int main(int argc, char* argv[])
{
	char* url = argv[argc-1];
	char* dom;
	char* ext;
	dom = (char*)malloc(BUFFER_SIZE*sizeof(char));
	ext = (char*)malloc(BUFFER_SIZE*sizeof(char));

	// get domain name + domain extension
	split_url(url, dom, ext);	
	
	size_t dom_length = strlen(dom);
	size_t ext_length = strlen(ext);

	char dom_base_bitstring[dom_length*8];
	char ext_base_bitstring[ext_length*8];
	
	// initialize string to "0"
        // this will be helpful when filling the bitstring with the bin representation of a char
        memset(dom_base_bitstring, '0', (int)dom_length*8);
        memset(ext_base_bitstring, '0', (int)ext_length*8);
	
	get_bitstring(dom, dom_base_bitstring);
	get_bitstring(ext, ext_base_bitstring);
	
	printf("%s \t->\t %.*s\n", dom, (int)dom_length*8, dom_base_bitstring);
	printf("%s \t->\t %.*s\n", ext, (int)ext_length*8, ext_base_bitstring);

	free(dom);
	free(ext);
	
	return(EXIT_SUCCESS);
}
