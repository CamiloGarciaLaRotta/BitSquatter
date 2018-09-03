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

// parse CLI flags to determine if user asked for help
bool asked_for_help(int num_args, char* args[])
{
	if (num_args == 1) return true;
	int i;
	for (i=0; i<num_args; i++)
	{
		if ((strcmp(args[i], "-h") == 0) || (strcmp(args[i], "--help") == 0))
		{
			return true;
		}
	}

	return false;
}

//TODO add better CLI flag error handling
// print to stdout the help
void print_help()
{
	printf("./bitsquat [-h|--help]\n");
	printf("./bitsquat [-v|--verbose] <domain_name.extension>\n\n");
	printf("Example: ./bitsquat --verbose foobar.com\n\n");
}

int main(int argc, char* argv[])
{
	if (asked_for_help(argc, argv))
	{
		print_help();
		exit(EXIT_SUCCESS);
	}

	const int BYTE = 8;
	const bool verbose = is_verbose(argc, argv);
	const char* url = argv[argc-1];

	if (verbose) printf("Target Domain: %s\n", url);

	char* dom = (char*)malloc(BUFFER_SIZE*sizeof(char));
	char* ext = (char*)malloc(BUFFER_SIZE*sizeof(char));

	split_url(url, dom, ext);

	if (verbose) printf("Domain Name: %s\tDomain extension: %s\n", dom, ext);

	const size_t dom_str_length = strlen(dom);
	const size_t ext_str_length = strlen(ext);
	const size_t dom_binary_length = dom_str_length*BYTE;
	const size_t ext_binary_length = ext_str_length*BYTE;

	char dom_binary_str[dom_binary_length];
	char ext_binary_str[ext_binary_length];
	memset(dom_binary_str, '0', (int)dom_binary_length);
	memset(ext_binary_str, '0', (int)ext_binary_length);

	get_binary_string(dom_str_length, dom, dom_binary_str);
	get_binary_string(ext_str_length, ext, ext_binary_str);

	if (verbose)
	{
		printf("%s:\t%.*s\n", dom, (int)dom_binary_length, dom_binary_str);
		printf("%s:\t%.*s\n", ext, (int)ext_binary_length, ext_binary_str);
	}

	// generate 1-bit permutations
	char dom_binary_permutations[dom_binary_length][dom_binary_length+1];
	char ext_binary_permutations[ext_binary_length][ext_binary_length+1];

	int i;
	for (i=0; i<(int)dom_binary_length; i++)
	{
		memcpy(dom_binary_permutations[i], dom_binary_str, dom_binary_length+1);
		dom_binary_permutations[i][dom_binary_length] = '\0';
	}
	for (i=0; i<(int)ext_binary_length; i++)
	{
		memcpy(ext_binary_permutations[i], ext_binary_str, ext_binary_length+1);
		ext_binary_permutations[i][ext_binary_length] = '\0';
	}

	for (i=0; i<(int)dom_binary_length; i++)
	{
		dom_binary_permutations[i][i] = (dom_binary_permutations[i][i]) == '1' ? '0' : '1';
	}
	for (i=0; i<(int)ext_binary_length; i++)
	{
		ext_binary_permutations[i][i] = (ext_binary_permutations[i][i]) == '1' ? '0' : '1';
	}

	// transform back to string
	char dom_str_permutations[dom_binary_length][dom_str_length+1];
	char ext_str_permutations[ext_binary_length][ext_str_length+1];

	for (i=0; i<(int)dom_binary_length; i++)
	{
		get_string(dom_binary_length, dom_binary_permutations[i], dom_str_permutations[i]);
		dom_str_permutations[i][dom_str_length] = '\0';
	}

	for (i=0; i<(int)ext_binary_length; i++)
	{
		get_string(ext_binary_length, ext_binary_permutations[i], ext_str_permutations[i]);
		ext_str_permutations[i][ext_str_length] = '\0';
	}

	// generate all possible combination of domain name & extension
	const int num_url_combinations = dom_binary_length * ext_binary_length;
	char url_permutations[num_url_combinations][dom_str_length + ext_str_length +2];
	int j, counter;
	counter = 0;
	for (i=0; i<(int)dom_binary_length; i++)
	{
		for (j=0; j<(int)ext_binary_length; j++)
		{
			memcpy(url_permutations[counter], dom_str_permutations[i], dom_str_length);
			url_permutations[counter][dom_str_length] = '.';
			memcpy(&url_permutations[counter][dom_str_length + 1], ext_str_permutations[j], ext_str_length);
			url_permutations[counter][dom_str_length + ext_str_length + 1] = '\0';

			counter++;
		}
	}

	for (i=0; i<num_url_combinations; i++)
	{
		if (is_valid_url(url_permutations[i])) printf("%s\n", url_permutations[i]);
	}

	free(dom);
	free(ext);

	return(EXIT_SUCCESS);
}
