// Exercise 2.8: Write a function rightrot(x,n) that returns the value of the integer rotated to 
// the right by n bit positions.


unsigned rightrot(unsigned x, unsigned n) {
  unsigned total_bits = 0;
  unsigned temp = ~0;

  while (temp != 0) {
    total_bits++;
    temp = temp >> 1; 
  }

  n = n % total_bits;
  
  return (x >> n) | (x << (total_bits - n));

}

  /*
   * Supongamos una máquina de 8 bits (total_bits = 8). Queremos rotar un número x = 11010111
   * (por ejemplo) unas n = 3 posiciones a la derecha. El resultado esperado es que los tres bits
   * de la derecha (111) pasen a la izquierda, quedando: 11111010.
   *
   * 1: x >> 3
   * ----------
   * Como son unsigned, entran ceros por la izquierda. Desplazamos 3 bits a la derecha.
   * Queda: 00011010
   *
   * 2: (x << (8 - 3)) = (x << 5)
   * -----------------------------
   * Digamos que esto es como recorrer el camino de vuelta, y ahí esta la magia del operador binario
   * OR. Con esta fórmula, queda:
   * 11100000
    
   OR (|):
   -------

   1:  0 0 0 1 1 0 1 0
   2:  1 1 1 0 0 0 0 0 
   -------------------- (|)
       1 1 1 1 1 0 1 0


   */

