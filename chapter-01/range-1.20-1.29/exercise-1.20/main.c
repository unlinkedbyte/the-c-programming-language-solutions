// Exercise 1.20: Write a program detab that replaces tabs in the input with the proper
// number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n 
// columns. Should n be a variable or a symbolic parameter?


#include <stdio.h>

#define TAB_STOP 8 // Distancia de los bloques 


int main(void) {

  int c, column, spaces, i;

  column = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      spaces = TAB_STOP - (column % TAB_STOP);
      for (i = 0; i < spaces; ++i) {
        putchar(' ');
        ++column;
      }
    } else if (c == '\n') {
      putchar(c);
      column = 0;
    } else {
      putchar(c);
      ++column;
    }

  }
  
  return 0;

}
