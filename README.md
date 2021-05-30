# Dum-dum-curl

Ultra simply http client written in C, and yes, it is pretty dumb.

It currently does not DNS resolve and therefore requires 2 args: 1) a hostname (for header purposes only, not really needed in the current implementation in all honesty), and 2) the IP of the server you are visiting - that's right, no DNS, sorry, might add something clever later - or you can use it as a starting point to build from!

The output is the HTTP response from the server, but note, it is limited currently to 1024 bytes (I mainly aimed for headers only for my own usage at the moment).

Note: Does not support HTTPS/TLS/SSL in any way currently, might add at some point.

# FAQ

## Does the title of the program make a very poor reference to a song on the 1984 Talk Talk album "It's my life"?
### 	Yes. Yes it does. 
