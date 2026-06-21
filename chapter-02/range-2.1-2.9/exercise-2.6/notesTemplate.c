// getbits: get n bits from position p

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}


/*
   Tenemos una secuencia de x bits y queremos recortar un trozo de esta tira (un campo de n bits)
   que empieza en la posición p, y dejar ese trozo limpio a la derecha del todo (right adjusted).
   getbits(x, 4, 3) queremos empezar en la posicion 4 (p = 4) y agarrar 3 bits en total (es decir,
   los bits de las posiciones 4, 3 y 2). Imaginemos que x tiene estos bits en memoria:

Posición de bits:    7  6  5  [4  3  2]  1  0 
Bits de x       :    1  0  1   1  1  0   0  1
                               ^  ^  ^
                               Queremos estos tres (110).
   El resultado final que queremos obtener es aislar ese 110 y moverlo a la derecha del todo:
   00000110.
   
   ------------------------------------------
   
   return (x >> (p+1-n)) & ~(~0 << n);
   
   Esta fórmula tiene dos partes unidas por un &. La parte izquierda mueve los bits que queremos
   a su sitio, y la parte derecha fabrica una "máscara limpia"(bitmask) para borrar todo lo demás.

   ------------------------------------------

   Parte 1: (x >> (p+1-n)):
   --------

   Si queremos mover los bits a la derecha, cuántas posiciones hay que empujarlos? la matemática
   con el ejemplo del k&r: p=4 y n=3:
  
   posiciones a desplazar: 4 + 1 - 3 = 2

   Hay que empujar x dos posiciones a la derecha (x >> 2):

   x original :    1  0  1  1  1  0  0  1
   primera vez:    0  1  0  1  1  1  0  0  (drop el 1 de la derecha)
   segunda vez:    0  0  1  0  1  1  1  0
                                  ^  ^  ^ (ya están a la derecha)

   Con esta fórmula, ya lo tenemos a la derecha. Por qué sumamos 1? Como estamos usando posiciones que
   empiezan en cero, la posición p=4 en realidad es el quinto bit. 
   Volviendo a la fórmula, ahora que tenemos el objetivo cumplido, tenemos un problema: a la izquierda
   de 110 todavia hay basura que hay que limpiar, y es donde entra la segunda parte.

   --------------------------------------------------


   Parte 2: Fabricar la bitmask ~(~0 << n)
   --------

   Paso A: ~0
   -----------

   El numero 0 son todo ceros. Al invertirlo con el operador unario (unary operator), creamos una fila
   del tamaño del procesador de unos.
   Ej: ~0 = 1111 1111 1111 1111

   Paso B: ~0 << n (donde en este caso n es 3)
   --------------------------------------------

   Desplazamos esa fila de unos 3 posiciones a la izquierda. Rellenamos los huecos de la derecha con
   ceros. 
   Ej: ~0 << 3 = 1111 1111 1111 1000

   Paso C: ~(~0 << n)
   -------------------

   Volvemos a invertir todo el bloque con el ~ de fuera. Los unos se vuelven ceros y los ceros, unos.
   Ej: ~(~0 << 3) = 0000 0000 0000 0111

    

   Para terminar: Uniendo la parte 1 y la parte 2
   -----------------------------------------------

   Parte 1 (x desplazado):   0000 0000 0010 1110
   Parte 2 (Máscara)     :   0000 0000 0000 0111
                             --------------------  (&)
                             0000 0000 0000 0110  (este es el resultado, en decimal es 6).


 */
