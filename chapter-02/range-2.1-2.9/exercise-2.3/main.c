// Exercise 2.3: Write the function htoi(s), which converts a string of hexadecimal digits (including
// an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9,
// a through f, and A through F.


#include <ctype.h>

int htoi(char s[]) {

  int i, n, valido, c_limpio;

  i = 0;
  n = 0;
  valido = 1;

  if (s[i] == '0') {
    if (s[i+1] == 'x' || s[i+1] == 'X') {
      i = i + 2;
    }
  }

  for (; valido == 1; ++i) {
    c_limpio = tolower(s[i]);

    if (isdigit(c_limpio)) {
      n = 16 * n + (c_limpio - '0'); 
    } else if (c_limpio >= 'a' && c_limpio <= 'f') {
      n = 16 * n + (c_limpio - 'a' + 10);
    } else {
      valido = 0;
    }
  }


  return n;

}
