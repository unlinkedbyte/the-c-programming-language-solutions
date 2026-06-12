// Exercise 1.22: Write a program to "fold" long input lines into two or more shorter 
// lines after the last non-blank character that occurs before the n-th column of input.
// Make sure your program does something intelligent with very long lines, and if there are no 
// blanks or tabs before the specified column.


#include <stdio.h>
#define MAXCOL 40
#define MAXLINE 1000

int main(void) {

  int c, i, last_space, leftover_count, j, k;
  char line[MAXLINE];
  char leftover[MAXLINE];

  last_space = -1;
  i = 0;
  leftover_count = 0;
  j = 0;
  k = 0;

  while ((c = getchar()) != EOF) {
    line[i] = c;
    if (c == ' ') {
      last_space = i;
    }

    if (c == '\n') {
      for (k = 0; k < i; ++k) {
        putchar(line[k]);
      }    
      putchar('\n');
      last_space = -1;
      i = 0;
      continue; // Saltará directamente a la siguiente vuelta del while principal
    }
    
    ++i;

    if (i >= MAXCOL) {
      if (last_space == -1) {
        for ( j = 0; j < MAXCOL; ++j) {
          putchar(line[j]);
        }
        putchar('\n');
        i = 0;
        
      } else {
        for (j = 0; j < last_space; ++j) {
          putchar(line[j]);
        }
        putchar('\n');
        
        // Este bucle es para guardar la palabra sobrante en un array, para poder imprimirla luego
        // y que no se pierda. 
        for (j = last_space + 1; j < i; ++j) {
          leftover[leftover_count] = line[j];
          ++leftover_count;
        }


        // Este es el bucle que coge la última palabra de la caja temporal y la deja al principio
        // del line. Así, la nueva línea empezará con esta palabra.
        for (j = 0; j < leftover_count; ++j) {
          line[j] = leftover[j];
        }

        i = leftover_count;

        last_space = -1;
        leftover_count = 0;

      }
      
    }

  }

  return 0;

}
