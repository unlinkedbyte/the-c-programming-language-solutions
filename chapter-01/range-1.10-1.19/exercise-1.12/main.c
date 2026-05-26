// Exercise 1.12: Write a program that prints its input one word per line.


#include <stdio.h>

#define IN 1 // inside a word
#define OUT 0 // outside a word

int main() {

  int c, state;

  state = OUT;

  while ((c = getchar()) != EOF) {

    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        putchar('\n');
        state = OUT;
      }
    } else {
      putchar(c);
      state = IN;
    }
  }

  return 0;

}











/* My first try (KISS style). The problem here can be more than one space

#include <stdio.h>

int main() {

  int c;

  while ((c = getchar()) != EOF) {
    
    if (c == ' ' || c == '\t') {
      c = '\n';
      putchar(c);
    } else {
      putchar(c);
    }
  }
  return 0;
}
*/
