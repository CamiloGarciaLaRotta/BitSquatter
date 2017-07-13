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

// return the bitstring representation of a string
void get_bitstring(const char* str, char bitstring[])
{
        int i;    // string index
        int Byte; // character index in bitstring
        for(i=0, Byte=7;i<strlen(str);i++,Byte+=8)
        {
                get_binary(str[i], Byte, bitstring);
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
