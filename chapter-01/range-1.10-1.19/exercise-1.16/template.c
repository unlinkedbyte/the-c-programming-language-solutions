// power: raise base to n-th power; n>=0; version 2
int power(int base, int n); {
  int p;

  for (p = 1; n > 0; --n) {
    p = p * base;
  }
  return p;
}

/* the most common type of array in C is the array of characters. 
 * To illustrate the use of character arrays and functions to manipulate them, let's write
 * a program that reads a set of text lines and prints the longest. The outline is simple enough:
 *
 * while (there's another line) {
 *  if (it's longer than the previous longest) {
 *      save it
 *      save its length
 *  } 
 * }
 * print longest line
 * */


