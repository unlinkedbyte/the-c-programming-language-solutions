void itoa(int n, char s[]) {

  int i, sign;

  sign = n;
  i = 0;

  do {
    int digit = n % 10;
    if (digit < 0) { digit = -digit; }
    s[i++] = digit + '0';
  } while ((n /= 10) != 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s); 
}
