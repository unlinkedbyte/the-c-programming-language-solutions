// Exercise 2.3: Write the function htoi(s), which converts a string of hexadecimal digits (including
// an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9,
// a through f, and A through F.

int htoi(char s[]) {

  int i, n, valido;

  i = 0;
  n = 0;
  valido = 1;

  if (s[i] == '0') {
    if (s[i+1] == 'x' || s[i+1] == 'X') {
      i = i + 2;
    }
  }

  for (; valido == 1; ++i) {
    if (s[i] >= '0' && s[i] <= '9') {
      n = 16 * n + (s[i] - '0');
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      n = 16 * n + (s[i] - 'a' + 10);
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      n = 16 * n + (s[i] - 'A' + 10);
    } else {
      valido = 0;
    }
  }

  return n;

}



