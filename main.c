#include <stdbool.h>
#include "bitsquat.h"

#define BUFFER_SIZE 80


// parse CLI flags to determine wether to be verbose or not
bool is_verbose(int num_args, char* args[])
{
	int i;
	for (i=0; i<num_args; i++)
	{
		if ((strcmp(args[i], "-v") == 0) || (strcmp(args[i], "--verbose") == 0))
		{
			return true;
		}
	}

	return false;
}

int main(int argc, char* argv[])
{
	const int BYTE = 8;
	const bool verbose = is_verbose(argc, argv);
	const char* url = argv[argc-1];

	if (verbose) printf("Target Domain: %s\n", url);

	char* dom = (char*)malloc(BUFFER_SIZE*sizeof(char));
	char* ext = (char*)malloc(BUFFER_SIZE*sizeof(char));

	split_url(url, dom, ext);

	if (verbose) printf("Domain Name: %s\tDomain extension: %s\n", dom, ext);

	const size_t dom_length = strlen(dom);
	const size_t ext_length = strlen(ext);
	const size_t dom_binary_length = dom_length*BYTE;
	const size_t ext_binary_length = ext_length*BYTE;

	char dom_binary_str[dom_binary_length];
	char ext_binary_str[ext_binary_length];
	memset(dom_binary_str, '0', (int)dom_binary_length);
	memset(ext_binary_str, '0', (int)ext_binary_length);

	get_binary_string(dom, dom_binary_str);
	get_binary_string(ext, ext_binary_str);

	if (verbose)
	{
		printf("%s:\t%.*s\n", dom, (int)dom_binary_length, dom_binary_str);
		printf("%s:\t%.*s\n", ext, (int)ext_binary_length, ext_binary_str);
	}

	// make array of arrays of size len(bitstring)
	// permutate each bit
	// transform back to string


	free(dom);
	free(ext);

	return(EXIT_SUCCESS);
}
