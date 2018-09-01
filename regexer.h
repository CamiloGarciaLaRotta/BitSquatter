#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <assert.h>
#include <sys/types.h>

// match_regex(pattern, to_match, start, end)
// match the given pattern in the string to_match
// the start and end position of the matched pattern are stored
// in the start and end pointers accordingly
int match_regex(const char*, const char*, int*, int*);
