// Exercise 1.13: Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. 


#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

  int c, i, state, word_len;
  int nlength[21]; 

  state = OUT; 
  
  word_len = 0; 
  

  for (i = 0; i < 21; ++i) {
    nlength[i] = 0;
  }

  
  while ((c = getchar()) != EOF) {
    
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        ++nlength[word_len];
        state = OUT;
        word_len = 0;
      }
    } else {
      state = IN;
      if (word_len < 20) { 
        ++word_len; // sumamos si no hemos llegado al límite del array
      }
    }

  }
  
  printf("\n[+] Results:\n");

  for (i = 1; i < 21; ++i) {
    printf("[+] Length of %d: %d words\n", i, nlength[i]);
  }

  return 0;

}
