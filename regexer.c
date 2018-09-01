#include "regexer.h"

// match the given pattern in the string to_match
// the start and end position of the matched pattern are stored accordingly
int match_regex(const char* pattern, const char* to_match, int* start, int* end)
{	
	assert(start);
	assert(end);
	
	regex_t r;
	size_t nmatch = 2;
	regmatch_t pmatch[2];
	
	int compile_status = regcomp(&r, pattern, REG_EXTENDED);
	if(compile_status != 0) return compile_status;

	int exec_status = regexec(&r, to_match, nmatch, pmatch, 0);
	if(exec_status != 0) return exec_status;

	*start = pmatch[1].rm_so;
	*end = pmatch[1].rm_eo;

	return EXIT_SUCCESS;
}
