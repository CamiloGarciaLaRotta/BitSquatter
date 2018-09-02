#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "regexer.h"

// fill an array with the binary representation of a character
void get_binary(int, int, char[]);

// return the bitstring representation of a string
void get_binary_string(const char*, char[]);

// split url into domain name and domain extension
void split_url(const char*, char*, char*);

