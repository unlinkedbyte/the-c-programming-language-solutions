// Exercise 2.6: Write a function setbits(x,p,n,y) that returns x with the n bits that begin
// at position p set to the rightmost n bits of y, leaving the other bits unchanged.

/*
    Este ejercicio nos pide que imaginemos que tenemos dos secuencias de bits (x e y) y que queremos
    hacer una operacion de cortar y pegar:
    
    1. Vamos a ir a y, vamos a mirar sus n bits de la derecha del todo y los vamos a copiar (romper
       el trozo)
    2. Vamos a ir a x, vamos a buscar la posición p, vamos a borrar los n bits que haya ahí para
       dejar hueco limpio, y vamos a pegar el trozo copiado de y.
 */


unsigned setbits(unsigned x, int p, int n, unsigned y) {
  x = x & ~(~(~0 << n) << (p + 1 - n) );
  y = (y &~(~0 << n)) << (p + 1 - n);

  return x | y;

}
