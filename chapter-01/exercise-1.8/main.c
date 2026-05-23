// Exercise 1.8: Write a program to count blanks, tabs and newlines.


#include <stdio.h>

int main() {

  int c, nl, tabs, blanks;

  nl = 0;
  tabs = 0;
  blanks = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
    }
    
    if (c == '\t') {
      ++tabs;
    }
    
    if (c == ' ') {
      ++blanks;
    }
  }
  
  printf("[+] Blanks count: %d\n", blanks);
  printf("[+] Tabs count: %d\n", tabs);
  printf("[+] Newlines count: %d\n", nl);

  return 0;
}



/*
#include <stdio.h>

// count lines in input
int main() {

  int c, nl;
  
  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
    }
  }
  
  printf("%d\n", nl);

  return 0;

}

Technical notes: 
The terminal input works as a stream of individual characters (a Stream). 
Typing '10' sends two independent bytes (the character '1' and the '0'). 
The only command that sends the real number 10 (00001010 in binary) is pressing the Enter key, 
which C interprets as the escape character '\n'.

*/



/*

#include <stdio.h>

// count characters in input

int main() {

  long nc;

  nc = 0;
  while (getchar() != EOF) {
    ++nc;
  }
  printf("%ld\n", nc);

  return 0;

  
}

Another way to write the loop with the for statement

#include <stdio.h>

int main() {

  double nc;

  for (nc = 0; getchar() != EOF; ++nc); // the semicolon here is the empty loop body 
                                        // because the grammatical rules of C require
                                        // that a for statement has a body

  printf("%.0f\n", nc);

  return 0;

}
*/
