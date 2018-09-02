#include "bitsquat.h"

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

// return the binary representation of a string
void get_binary_string(const int str_length, const char* str, char binary_str[])
{
        int i;    // string index
        int byte; // character index in binary string
        for(i=0, byte=7; i<str_length; i++, byte+=8)
        {
                get_binary(str[i], byte, binary_str);
        }
}

// split url into domain name and domain extension
void split_url(const char* url, char* dom, char* ext)
{
        int start, end;

        match_regex("^[[:alnum:]]*(.)[[:alnum:].]*", url, &start, &end);

        sprintf(dom, "%.*s", (start), url);
        sprintf(ext, "%.*s", (int)strlen(url)-end, url+start+1);
}
