// Added challenge for practice
// counting vocals


#include <stdio.h>

int main() {

  int c, i, j;
  int vocals[5];

  for (i = 0; i < 5; ++i) {
    vocals[i] = 0;
  }


  while ((c = getchar()) != EOF) {
  
    if (c == 'a' || c == 'A') {
      ++vocals[0];
    } else if (c == 'e' || c == 'E') {
      ++vocals[1];
    } else if (c == 'i' || c == 'I') {
      ++vocals[2];
    } else if (c == 'o' || c == 'O') {
      ++vocals[3];
    } else if (c == 'u' || c == 'U') {
      ++vocals[4];
    } else {
      putchar(c);
    }
  }
  
  printf("\n[+] Histogram of vocals:\n");

  for (j = 0; j < 5; ++j) {
    if (vocals[j] > 0) {
      if (j == 0) {
        printf(" a/A : ");
      } else if (j == 1) {
        printf(" e/E : ");
      } else if (j == 2) {
        printf(" i/I : ");
      } else if (j == 3) {
        printf(" o/O : ");
      } else if (j == 4) {
        printf(" u/U : ");
      }

      for (i = 0; i < vocals[j]; ++i) {
        putchar('*');
      }
      putchar('\n');
    }
  }

  return 0;
}
