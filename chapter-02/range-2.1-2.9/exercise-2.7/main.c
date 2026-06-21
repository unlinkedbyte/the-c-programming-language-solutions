// Exercise 2.7: Write a function invert(x,p,n) that returns x with the n bits that begin
// at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged

unsigned invert(unsigned x, int p, int n) {
  /* ~(~0 << n) << (p + 1 - n) crea unos en las posiciones deseadas y ceros en el resto.
   * El operador XOR (^) invierte los bits que se comparan contra 1 y deja intactos los que se 
   * comparan contra 0.
   */
  x = x ^(~(~0 << n) << (p + 1 - n));
  return x;
}
