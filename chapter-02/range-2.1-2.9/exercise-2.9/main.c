// Exercise 2.9: In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
// Explain why. Use this obsercation to write a faster version of bitcount.


/* 
   Explanation:
   ------------
   First of all, x &= (x-1) equals to x = x & (x-1). After testing with decimal numbers, we can
   observe that subtracting one from a binary number (x-1) transforms the least significant 1 bit
   (the rightmost one) into 0, while turning all the 0 bits to its right into 1. By applying the
   bitwise AND assignment operator (&=), this result is compared against the original number of x.
   This leaves the bits on the left untouched, but turns both the original rightmost 1 bit and
   the bits on its right into 0. This approach is more efficient because the loop only executes as
   many times as there are 1 bits in the number, eliminating the "unnecessary" bit shifts that would
   otherwise be required to evaluate every single position.
*/


unsigned int bitcount(unsigned int x) {
  
  unsigned int count = 0;


  while (x != 0) {
    x &= (x - 1);
    count++;
  }

  return count;
}

