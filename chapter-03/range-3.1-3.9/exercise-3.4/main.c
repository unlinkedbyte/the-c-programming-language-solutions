// Exercise 3.4: In a two's complement number representation, our version of itoa does not handle the
// largest negative number, that is, the value of n equal to -(2^wordsize-1). Explain why not. Modify
// it to print that value correctly, regardless of the machine on which it runs.


/* Explanation:
   ------------
  
   The reason is that in the two's complement system used by CPUs to represent signed numbers, the
   range of values an int can store is asymmetrical, so there is one more negative number than there
   are positive numbers. For example, in a 16 bit (2byte) system, the range goes from 
   -32768 to 32767. The code attemps to convert the number into a positive value by doing n = -n;. 
   Therefore, if you calculate -(-32.768), the mathematical result is 32768. This causes an integer 
   overflow, forcing the number back to -32768, making it as if that block of code did nothing at all.
   Upon reaching the do-while loop as a negative number, the modulo (% 10) and division (/ 10) 
   operations return incorrect remainders or trigger infinite loops depending on the machine, causing
   undefined behaviour.
*/

void itoa(int n, char s[]) {

  int i, sign;

  i = 0;
  sign = n;

  do {
    s[i++] = ((sign < 0) ? -(n % 10) : (n % 10)) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);

}
