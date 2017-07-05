#include "header.h"

// compile regex
int compile_regex(regex_t* r, const char* pattern)
{
	int status = regcomp(r, pattern, REG_EXTENDED);
	if(status != 0)	
	{
		char err_message[BUFFER_SIZE];
		regerror(status, r, err_message, BUFFER_SIZE);
		printf("Error compiling regex.\n %s: %s\n", pattern, err_message);
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}

// execute regex
int exec_regex(regex_t* r, const char* to_match, int* start, int* end)
{
	// check that pointers are not pointing to NULL
	assert(start);
	assert(end);

	size_t nmatch = 2;
	regmatch_t pmatch[2];
	int status = regexec(r, to_match, nmatch, pmatch, 0);
	if(status != 0)	
	{
		*start = -1;
		*end = -1;
	}
	else
	{
		*start = pmatch[1].rm_so;
		*end = pmatch[1].rm_eo;
	}

	return EXIT_SUCCESS;
}

// match pattern in string
int match_regex(const char* pattern, const char* to_match, int* start, int* end)
{	
	regex_t r;
	
	compile_regex(&r, pattern);
	exec_regex(&r, to_match, start, end);
	
//	printf("Matched substring: %.*s\n", (end-start), to_match+start );
//	printf("Matched position: %d to %d\n", start, end);
	
	regfree(&r);
	
	if (*start == -1)
	{
		return EXIT_FAILURE;
	} 	
	else
	{
		return EXIT_SUCCESS;
	}

}
