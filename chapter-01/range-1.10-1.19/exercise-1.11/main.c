// Exercise 1.11: How would you test the word count program? 
// What kinds of input are most likely to uncover bugs if there are any? 



/* 
 Based on our code, what I would do is check what happens if there is more than one space between words. 
 What happens if there are multiple tabs or more line breaks than there should be? 
 Also, what if we separate words using commas or special characters like |? 
 And what happens if I type a word and close the program, skipping the last Enter?

 I would even add the issue with integers.
 Knowing that C allocates 4 bytes by default when we declare an int variable, 
 and knowing that signed int variables use the first bit for the sign, we would have to look at 2^31.
 In any case, I could try pushing it to the maximum allowed characters just to see how the program 
 behaves—even though entering more than 2 billion characters without automation or loops would be
 complete madness
*/


/*
#include <stdio.h>


#define IN 1  // inside a word
#define OUT 0 // outside a word


// Count lines, words, and characters in input

int main() {

  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("New line count: %d. New word count: %d. New character count: %d\n", nl, nw, nc);


  return 0;
}
*/ 
