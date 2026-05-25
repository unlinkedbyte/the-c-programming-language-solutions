// Exercise 1.6: Verify that the expression getchar() != EOF is 0 or 1.

// the standard approach, definitive version after some research 
#include <stdio.h>

int main() {

  int c;

  printf("\n[+] Input a character, or trigger EOF using Ctrl+D to test the expression: \n\n");

  c = (getchar() != EOF);

  printf("\n[+] The value of the expression 'getchar() != EOF' is '%d'\n\n", c);

  return 0;
}


/* My first code
#include <stdio.h>

int main() {
  
  int c;
  c = (getchar() != EOF);
  printf("\n[+] The value of the expression getchar != EOF is '%d'\n\n", c);
  

  return 0;
}
*/


/* First version

#include <stdio.h>


int main() {

  int c; // Why c is an integer?

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
  return 0;

} 
*/


///////


/* Second version
 
#include <stdio.h>

// copy input to output; 2nd version

int main() {
  
  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);
  }

  // The parentheses are necessary. The precedence of != is higher than that of = 
  // which means that in absence of parentheses the relational test != would be done before the assignment. 
  // c = getchar() != EOF is equal to c = (getchar() != EOF)
  
  return 0;
}
*/
