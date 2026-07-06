// Exercise 3.6: Write a version of itoa that accepts three arguments instead of two. The third
// argument is a minimum field width; the converted number must be padded with blanks on the left if
// necessary to make it wide enough.


void itoa(int n, char s[], int w) {
  
  int i, sign;

  i = 0;
  sign = n;

  do {
    s[i++] = ((sign < 0) ? -(n % 10) : (n % 10)) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  for (; i < w;) {
    s[i++] = ' ';
  }

  /*
  we can use this, its more readable:
  while (i < w) {
    s[i++] = ' ';
  }
   */

  s[i] = '\0';
  reverse(s);

}
