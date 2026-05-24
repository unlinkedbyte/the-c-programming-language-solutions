// Exercise 1.9: Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank


#include <stdio.h>

int main() {

  int c, blank;
  
  // blank will be a state flag (switch). 0 means allowed and 1 is equal to blocked. 

  blank = 0; // initialize the flag to allowed

  while ((c = getchar()) != EOF) {
    
    // Case A: the current character is not a blank space 
    if (c != ' ') {
      putchar(c); // print it directly to output
      blank = 0;  // This is the key reset: reset flag to 0 
                  // because the sequence of spaces has broken 
    } 
    // Case B: the current character is a blank
    else { 
      // Only allow printing if the flag is 0 or allowed (it is the first space of the sequence)
      if (blank == 0) {
        putchar(c); // prints the first authorized space
        ++blank;  // the key switch: it sets the flag to 1. Subsequent spaces will bounce off the
                  // condition
      }
    }
    
  }
  return 0; 
}
