// Exercise 1.14: Write a program to print a histogram of the frequencies of different characters
// in its input.
// (By frequencies we can understand "how many times something appears?", so we have to count how many times every character or simbol is repeated)

#include <stdio.h>

#define ASCII_SIZE 128

int main() {
    
  int c, i, j;
  int nchars[ASCII_SIZE]; 

  for (i = 0; i < ASCII_SIZE; ++i) {
    nchars[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= 0 && c < ASCII_SIZE) {
      ++nchars[c];
    }
  }
  
  printf("\n[+] Histogram of the frequencies:\n");
 
  for (i = 0; i < ASCII_SIZE; ++i) {
    if (nchars[i] > 0) {
      if (i == '\n') {
        printf(" \\n : ");
      } else if (i == '\t') {
        printf(" \\t : ");
      } else if (i == ' ') {
        printf("' ' : ");
      } else {
        printf(" %2c : ", i);
      }
    
    
      for (j = 0; j < nchars[i]; ++j) {
        putchar('*');
      }
      putchar('\n');
    }
  }


  return 0;

}
