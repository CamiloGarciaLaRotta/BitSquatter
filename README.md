
<img src="https://i.imgur.com/nboh344.jpg " alt="BitSquatter" width="300">

> Logo by Xinh Studio from the Noun Project

[![Build Status](https://travis-ci.org/CamiloGarciaLaRotta/BitSquatter.svg?branch=master)](https://travis-ci.org/CamiloGarciaLaRotta/BitSquatter)
# Theory
**[Bitsquatting](http://dinaburg.org/bitsquatting.html)** refers to the registration of a domain names one bit different than a popular domain. It is a form of **[Cybersquatting](https://en.wikipedia.org/wiki/Cybersquatting)**.

<!--It does so by splitting the URL into domain name and domain extension.  
Then it transforms the strings into their binary equivalents.  
Finally it queries WHOIS servers with all the 1-bit permutations of the binary strings.-->

# Usage
1. Compile: `make bitsquat`
2. Run: `./bisquat toto.com`

# Documentation
```bash
Given a domain name, BitSquatter will output to stdout all the domains different by 1 bit.

./bitsquat [-h|--help]
./bitsquat [-v|--verbose] <domain_name.extension>

Example: ./bitsquat --verbose foobar.com
foorar.com
foorar.com
foorar.com
foorar.com
foobar.coo
foobar.col
```
