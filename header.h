#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <assert.h>
#include <sys/types.h>

#define BUFFER_SIZE 80

int match_regex(const char*, const char*, int*, int*);
