#include "regexer.h"

// match the given pattern in the string to_match
// the start and end position of the matched pattern are stored accordingly
int match_regex(const char *pattern, const char *to_match, int *start, int *end)
{
	assert(start);
	assert(end);

	regex_t r;
	size_t nmatch = 2;
	regmatch_t pmatch[2];

	int compile_status = regcomp(&r, pattern, REG_EXTENDED);
	if (compile_status != 0)
	{
		regfree(&r);
		return compile_status;
	}

	int exec_status = regexec(&r, to_match, nmatch, pmatch, 0);
	regfree(&r);
	if (exec_status != 0)
	{
		return exec_status;
	}

	*start = pmatch[1].rm_so;
	*end = pmatch[1].rm_eo;

	return EXIT_SUCCESS;
}

// return wether or not the regex matches the string
bool match(const char *pattern, const char *to_match)
{
	regex_t r;

	int compile_status = regcomp(&r, pattern, REG_EXTENDED);
	if (compile_status != 0)
	{
		regfree(&r);
		return compile_status;
	}

	int exec_status = regexec(&r, to_match, 0, NULL, 0);
	regfree(&r);
	if (exec_status == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
