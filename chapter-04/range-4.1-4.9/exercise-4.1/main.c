// Exercise 4.1: Write the function strrindex(s,t) which returns the position of the rightmost
// occurrence of the in s, or -1 if there is none.

#include <string.h> // strlen

int strrindex(char s[], char t[]) {
  
  int i, j, k;
  int length = strlen(s);
  
  for (i = length - 1; i >= 0; i--) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
      ;
    }

    if (k > 0 && t[k] == '\0') {
      return i;
    }
  }

  return -1;
}


/* alternative version without strlen

int strrindex(char s[], char t[]) {
  int i, j, k;
  int pos = -1; 

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
      ;
    }
    
    if (k > 0 && t[k] == '\0') {
      pos = i;
    }
  }
  
  return pos;
}
