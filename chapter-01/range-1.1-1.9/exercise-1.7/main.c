// Exercise 1.7: Write a program to print the value of EOF.


#include <stdio.h>

int main() {

  printf("[+] The value of EOF is '%d'\n", EOF);

  return 0;
}

/*
 Technical notes: 

 1. Where is EOF defined?
    EOF is a Macro defined in the <stdio.h> header file (usually as '#define EOF -1')
    It's a symbolic constant, not a regular variable

 2. Why can't we use a 'char' to store it?
    A standard char in C typically occupies 1 byte of memory, allowing it
    to hold 256 distinct values (0 to 255 if unsigned)

    Since getchar() needs to return every possible valid character value and a unique
    signal for the end-of-file (which is -1), a char is not wide enough to safely
    distinguish EOF from a legitimate character (like the character ÿ with value 255 in some systems).

    By returning an int (usually 4 bytes), C ensures there are plenty of bits to store 
    all 256 characters as positive values, while keeping -1 completely distinct.

    What is a macro? 
    A macro is a rule that instructs the compiler to transform text within your source
    before the actual compilation takes place. To understand this at a low level, we need to look
    at the C preprocessor. 

 */
