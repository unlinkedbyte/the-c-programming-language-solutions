#include <stdio.h>

#define MAXLINE 1000  // Maximum input line size

// Las variables globales, a diferencia de las locales, se inicializan automáticamente en 0 al 
// comenzar el programa. Si es un int, se pone a 0. Si es un char, se pone a '\0'. 

/* Debemos poner siempre extern para referirnos a una variable global?
 * No siempre. Solo es obligatorio en dos casos: 
 * 1. Si usas la variable en una línea de código que está más arriba de donde la definiste.
 * 2. Si la variable está en un archivo de código diferente (.c) y quieres usarla en el archivo
 * actual.
 * Si defines la variable arriba del todo en tu archivo, las funciones que están abajo la ven auto-
 * máticamente y puedes omitir la palabra extern. En el K&R lo ponen para que aprendas cómo se
 * estructura formalmente. 
*/

// Definición: Es donde se crea la variable y se le reserva memoria (ej. int max; fuera de las 
// funciones). Solo puede haber una.
// Declaración: Se refiere a los sitios donde la naturaleza(el tipo) de la variable es declarada pero no se
// le ha reservado memoria. Se refiere exactamente a que el compilador no va a buscar un hueco
// libre en la RAM para crear esa variable (existe en otra parte). 

int max; // maximum length seen so far
char line[MAXLINE]; // current input line
char longest[MAXLINE]; // longest line saved here

int getline(void);
void copy(void);


// Print longest input line; specialized version

int main(void) {

  int len; 
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }

  if (max > 0) { // there was a line
    printf("%s", longest);
  }

  return 0;
}


// getline: specialized version

int getline(void) {

  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line [i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}


// copy: specialized version

void copy(void) {

  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0') {
    ++i;
  }
}
