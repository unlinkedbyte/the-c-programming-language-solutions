// Exercise 2.1: Write a program to determine the ranges of char, short, int, and long variables,
// both signes and unsigned, by printing appropiate values from the standard headers and by direct
// computation. Harder if you compute them: determine the ranges of the various floating-point types.


#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(void) {

  printf("\n[+] Max size for data types signed: \n");

  printf("\t-> char: '%d'.\n\t-> short: '%d'.\n\t-> int: '%d'.\n\t-> long: '%ld'\n", SCHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX);

  printf("\n[+] Min size for data types signed:\n");
  printf("\t-> char: '%d'.\n\t-> short: '%d'.\n\t-> int: '%d'.\n\t-> long: '%ld'\n", SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);

  printf("\n[+] Ranges:\n");
  printf("\t-> char: '%d' - '%d'\n", SCHAR_MIN, SCHAR_MAX);
  printf("\t-> short: '%d' - '%d'\n", SHRT_MIN, SHRT_MAX);
  printf("\t-> int: '%d' - '%d'\n", INT_MIN, INT_MAX);
  printf("\t-> long: '%ld' - '%ld'\n", LONG_MIN, LONG_MAX);

  printf("\n[+] Max values of unsigned variables:\n");
  printf("\t-> unsigned char: '%u'\n", UCHAR_MAX);
  printf("\t-> unsigned short: '%u'\n", USHRT_MAX);
  printf("\t-> unsigned int: '%u'\n", UINT_MAX);
  printf("\t-> unsigned long: '%lu'\n", ULONG_MAX);



  printf("\n\n[+] === COMPUTATION ===\n\n");
  printf("[+] First option: Overflow\n");
  // Esta opción parece sencilla, funciona como un cuentakilómetros de un coche. Si avanza un 
  // kilómetro de más, el marcador se desborda y vuelve a 0. En binario pasa exactamente igual.
  // Si a una variable sin signo que vale 0 le restamos 1, como no tiene números negativos, da la 
  // vuelta completa hacia atrás y se transforma en el número más grande posible. 
  unsigned char max_char = 0;
  unsigned short max_short = 0;
  unsigned int max_int = 0;
  unsigned long max_long = 0;

  max_char = max_char - 1; 
  max_short = max_short - 1;
  max_int = max_int - 1;
  max_long = max_long - 1;

  printf("\t-> char: '%u'\n", max_char);
  printf("\t-> short: '%u'\n", max_short);
  printf("\t-> int: '%u'\n", max_int);
  printf("\t-> long: '%lu'\n", max_long);

  
  printf("\n[+] Second option: Pure maths\n");
 
  /* Las variables con signo usan 1 bit para el signo, por lo tanto, n - 1 bits para almacenar 
   * el número. sizeof() nos dirá cuantos bytes ocupa cada tipo de variable.
   * 2^bits-1 - 1 para el valor máximo
   * -2^bits-1 para el valor mínimo
   * Ejemplo con char (8 bits totales -> 7 bits para el número):
   * 2^7 = 128. Máximo: 128 - 1 = 127. Mínimo: -128 = -128
   * En lugar de usar funciones de potencias, podemos usar el operador de desplazamiento de bits
   * a la izquierda (<<), que calcula potencias de 2 de forma nativa en el procesador. Escribir 
   * 1 << 7 significa 2 elevado a 7. 
   */
  
  /*
  int bits_char = sizeof(char) * 8;
  int maximo_char = (1 << (bits_char - 1)) - 1;
  int minimo_char = -(1 << (bits_char -1));
  

  int bits_short = sizeof(short) * 8;
  int maximo_short = (1 << (bits_short - 1)) - 1;
  int minimo_short = -(1 << (bits_short - 1));


  int bits_int = sizeof(int) * 8;
  int maximo_int = (1 << (bits_int - 1)) - 1;
  int minimo_int = -(1 << (bits_int - 1));


  long bits_long = sizeof(long) * 8;
  long maximo_long = (1L << (bits_long - 1)) - 1;
  long minimo_long = -(1L << (bits_long - 1));
  */
  

  /* Por qué calculamos los tipos con signo dividiendo el 'unsigned entre 2?
   * Primero por portabilidad y seguridad. Operaciones como '1 << 31' meten un bit en la posición del
   * signo de la variable signed. Según el estándar de C, esto es comportamiento indefinido.
   * El programa como tal podría dar resultados raros en otros compiladores.
   * Al coger el máximo absoluto que obtenemos de la primera opción (overflow), y dividirlo entre 2, 
   * obtenemos matemáticamente el limite máximo con signo de forma segura, limpia y portable
   */
  int maximo_char  = max_char / 2;
  int minimo_char  = -maximo_char - 1;

  int maximo_short = max_short / 2;
  int minimo_short = -maximo_short - 1;

  int maximo_int   = max_int / 2;
  int minimo_int   = -maximo_int - 1;

  long maximo_long = max_long / 2;
  long minimo_long = -maximo_long - 1;


  printf("[+] Range values of data types with sign:\n");
  printf("\t-> char: '%d' - '%d'\n", minimo_char, maximo_char);
  printf("\t-> short: '%d' - '%d'\n", minimo_short, maximo_short);
  printf("\t-> int: '%d' - '%d'\n", minimo_int, maximo_int);
  printf("\t-> long: '%ld' - '%ld'\n", minimo_long, maximo_long);




  


  return 0;
}
