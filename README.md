# Bitcoin Encryption

Implementation a modified version of SHA256 algorithm named SUDO-SHA256.

## About the code

Has the following modules:

### Pad Parse

This module will get the message and parse it to 512 bit message blocks with the following segments.

|Up to 448 bits|448 - DataSize bits|1 bit|63 Bits|
|---|----|---|---|
|Data|Padding Zeros|Padding One|Main Message Size|

### Expansion

### Compression

## Compiling Environment
Implemented via C++ 98
If you want to compile with the Xilinx SDK uncomment the following line in `const.h` file.
~~~c
#define XILINIX_SDK
~~~