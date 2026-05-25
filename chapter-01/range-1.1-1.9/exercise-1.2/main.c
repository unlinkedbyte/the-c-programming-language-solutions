// Exercise 1.2: Experiment to find out what happens when printf's argument string contains \c, where c is some character not listed above


#include <stdio.h>

int main() {
  printf("hello, world\n"); // \c instead of \n or before 
  return 0;
}

// If you use the character sequence \c, since it doesn't exist as a valid escape sequence in C, the compiler will trigger an 'unknown escape sequence' warning inside the main function.
