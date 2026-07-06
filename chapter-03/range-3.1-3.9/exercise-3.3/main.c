// Exercise 3.3: Write a function expand(s1,s2) that expands shorthand notations like a-z in the 
// string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
// and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a 
// leading or trailing - is taken literally. 

#include <ctype.h>

void expand(char s1[], char s2[], int max_size_s2) {
  /*
  Although the exercise does not require it, I am implementing defensive code.
  I am adding the 'max_size_s2' parameter because in C, arrays decay to pointers 
  (pointer decay) when passed as arguments to a function. The function only receives 
  the initial memory address and loses track of the original buffer size,
  so it can cause buffer overflows.
   */
    
  int i = 0;
  int j = 0;

  while (s1[i] != '\0' && j < max_size_s2 - 1) {
      
      if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0') {
          
        char start = s1[i - 1];  
        char end = s1[i + 1];
        int is_valid = 0;

        unsigned char u_start = (unsigned char)start;
        unsigned char u_end = (unsigned char)end;

        if (islower(u_start) && islower(u_end)) {
          is_valid = 1;
        } else if (isupper(u_start) && isupper(u_end)) {
          is_valid = 1;
        } else if (isdigit(u_start) && isdigit(u_end)) {
          is_valid = 1;
        }

        if (is_valid && start < end) {
          for (char c = start + 1; c <= end && j < max_size_s2 - 1; c++) {
            s2[j++] = c;
          }
        
        i += 2;
        continue; 
        
        }
    }

    s2[j++] = s1[i++];
  
  }

  if (max_size_s2 > 0) {
      s2[j] = '\0';
  }
}

