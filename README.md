
<img src="https://i.imgur.com/nboh344.jpg " alt="BitSquatter" width="300">

> Logo by Xinh Studio from the Noun Project

[![Build Status](https://travis-ci.org/CamiloGarciaLaRotta/BitSquatter.svg?branch=master)](https://travis-ci.org/CamiloGarciaLaRotta/BitSquatter)
# Theory
**[Bitsquatting](http://dinaburg.org/bitsquatting.html)** refers to the registration of a domain names one bit different than a popular domain.  
It is a form of **[Cybersquatting](https://en.wikipedia.org/wiki/Cybersquatting)**.

It does so by splitting the URL into domain name and domain extension.  
Then it transforms the strings into their binary equivalents.  
It then generates all the 1-bit permutations of the binary strings.

# Usage
1. Compile: `make bitsquat`
2. Run: 
    ```bash
    $ ./bitsquat --verbose foobar.com
    Target Domain: foobar.com
    Domain Name: foobar     Domain extension: com
    foobar: 011001100110111101101111011000100110000101110010
    com:    011000110110111101101101
    Foobar.Com
    Foobar.som
    Foobar.kom
    Foobar.gom
    Foobar.aom
    Foobar.bom
    Foobar.cOm
    ...
    ```

# Documentation
```bash
$ ./bitsquat --help
Usage: bitsquat [OPTION...] [URL]
BitSquatter outputs all valid domains different by 1 bit from the input URL.

Example: bitsquat --verbose foobar.com

  -v, --verbose              Display domain name and extension bitstrings
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version
```
