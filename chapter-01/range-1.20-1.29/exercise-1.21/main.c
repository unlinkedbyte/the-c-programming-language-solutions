// Exercise 1.21: Write a program entab that replaces strings of blanks by the minimum number of 
// tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either
// a tab or a single blank would suffice to reach a tab stop, which should be given preference? 


#include <stdio.h>

#define TAB_STOP 8

int main(void) {
  int c, i, column, spaces;

  spaces = 0;
  column = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++spaces;
      ++column;
      if (column % TAB_STOP == 0) {
        putchar('\t');
        spaces = 0;
      }
    } else {
      for (i = 0; i < spaces; ++i) {
        putchar(' ');
      }
      spaces = 0;

      if (c == '\n') {
        putchar(c);
        column = 0;
      } else if (c == '\t') {
        putchar(c); 
        column = column + (TAB_STOP - (column % TAB_STOP));
      } else {
        putchar(c);
        ++column;
      }
    
    }

  }

  return 0;
}

