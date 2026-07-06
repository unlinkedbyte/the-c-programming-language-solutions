// Exercise 3.5: Write the function itob(n,s,b) that converts the integer n into a base b character
// representation in the string s. In particular, itob(n,s,16) formats n as a hexadecimal integer in s


void itob(int n, char s[], int b) {
  
  int i, sign;

  /* Lookup Table:
     -------------

     A lookup table is a data structure used to replace complex calculation operations or multiple 
     conditional structures (such as numerous if or switch statements) with a single direct memory 
     access operation. Instead of determining the result at runtime, the program simply looks up the 
     precalculated or predefined value at a specific array index.
   */

  char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz"; // lookup table
 
  i = 0;
  sign = n;


  do {
    s[i++] = digits[((sign < 0) ? -(n % b) : (n % b))];
  } while ((n /= b) != 0);
 
  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}
