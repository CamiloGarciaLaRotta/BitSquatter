
<a href="https://travis-ci.org/CamiloGarciaLaRotta/BitSquatter" alt="build status"><img align="right" src="https://travis-ci.org/CamiloGarciaLaRotta/BitSquatter.svg?branch=master"></a>
<p align="left">
<img src="https://i.imgur.com/nboh344.jpg " alt="BitSquatter" width="200">
<br>
<code>Logo by Xinh Studio @Noun Project</code>
</p>

# Theory
**[Bitsquatting](http://dinaburg.org/bitsquatting.html)** refers to the registration of a domain names one bit different than a popular domain.  
It is a form of **[Cybersquatting](https://en.wikipedia.org/wiki/Cybersquatting)**.

The overall process is as follows:
1. Split the URL into domain name and domain extension
2. Transform both strings into their binary equivalents
3. Generate all the 1-bit permutations of each bitstring
4. Transform the bitstrings back to characters
5. Filter out any non URL valid strings

# Usage
1. Compile: `make bitsquat`
2. Run: 
    ```bash
    ./bitsquat --verbose foo.com
    Target Domain: foo.com
    Domain Name: foo        Domain extension: com
    foo:    011001100110111101101111
    com:    011000110110111101101101
    doo.com
    goo.com
    fOo.com
    fgo.com
    fko.com
    fmo.com
    fno.com
    foO.com
    ...
    ```

# Documentation
```bash
$ ./bitsquat --help
Usage: bitsquat [OPTION...] [URL]
BitSquatter outputs all valid domains different by 1 bit from the input URL.

Example: bitsquat --verbose foobar.com

  -e, --extension-too        Generate URL permutations for the extension too
  -v, --verbose              Display domain name and extension bitstrings
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version
```
