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
  
  printf("[+] Vertical histogram:\n");

  int max_words = 0;

  for (i = 1; i < 21; ++i) {     
    if (nlength[i] > max_words) {
      max_words = nlength[i];     
    }
  }
  for (; max_words > 0; --max_words) {
    
    printf("Row %2d: ", max_words);
  
    for (i = 1; i < 21; ++i) {
      if (nlength[i] >= max_words) {
        putchar(' ');
        putchar('*');
        putchar(' ');
      } else {
        putchar(' ');
        putchar(' ');
        putchar(' ');

      }
    }
    putchar('\n');
  }
  
  printf("Floor : ");

  for (i = 1; i < 21; ++i) {
    printf("%2d ", i);
  }
  putchar('\n');
  

  return 0;

}
