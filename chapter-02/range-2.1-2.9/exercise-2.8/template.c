// Exercise 2.8: Write a function rightrot(x,n) that returns the value of the integer rotated to 
// the right by n bit positions.

unsigned rightrot(unsigned x, unsigned n) { // Declaramos unsigned n para que no nos puedan meter
                                            // datos inesperados como un número negativo ya que ahora
                                            // introducimos un bucle
  
  
  int total_bits = sizeof(x) * 8;
  n = n % total_bits;
  int jump = total_bits - 1;

  while (n > 0) {

    unsigned last_bit = x & 1;
  
    x = x >> 1;

    unsigned left_bit = last_bit << jump;

    x = x | left_bit;
    
    --n;
  }

  return x;


}
