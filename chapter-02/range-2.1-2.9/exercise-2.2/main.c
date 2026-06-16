// Exercise 2.2: Write a loop equivalent to the for loop above without using && or ||.

// The loop in question: 
// for (i = 0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
//  s[i] = c;


#include <stdio.h>
#define LIM 1000
#define TRUE 1
#define FALSE 0

int main(void) {
  int c, i, ok;
  char s[LIM];
  
  ok = TRUE;
  
  for (i = 0; ok == TRUE; ) {

    if (i >= LIM - 1) {
      ok = FALSE;
    } else {
      c = getchar();
      if (c == '\n') {
        ok = FALSE;
      } else if (c == EOF) {
        ok = FALSE;
      } else {
        s[i] = c;
        ++i;
      }
    }
  }
 
  s[i] = '\0';

  
  return 0; 

}

/*

#include <stdio.h>
#define LIM 1000

int main(void) {
  int c, i;
  char s[LIM];
  int longitud_real = 0; // Guardará el tamaño real de la cadena

  i = 0;
  while (i < LIM - 1) {
    c = getchar();
    
    if (c == '\n') {
      longitud_real = i; // Guardamos la posición actual antes de romper 'i'
      i = LIM;           // Forzamos la salida del bucle
    } else if (c == EOF) {
      longitud_real = i;
      i = LIM;          
    } else {
      s[i] = c;
      ++i;
    }
  }

  
  if (i >= LIM) {
    ;
  } else { 
    longitud_real = i;
  }

  // Ahora podemos poner el cierre de cadena de forma segura en su sitio
  s[longitud_real] = '\0';

  return 0;
}

 */
