// Exercise 1.16: Revise the main routine of the longest-line program so it will correctly
// print the length or arbitrarily long input lines, and as much as posible of the next



#include <stdio.h>
#define MAXLINE 1000 // maximum input line size

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);


// print longest input line

int main() {
  int len; // current line length
  int max; // maximum length seen so far
  char line[MAXLINE]; // current input line
  char longest[MAXLINE]; // longest line saved here
  
  max = 0; 
  while ((len = my_getline(line, MAXLINE)) > 0) { // getline was causing compilation errors, so I renamed the function to a custom name
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {  // there was a line
    printf("%s", longest);
  }
  return 0;
}


// getline: read a line into s, return length
int my_getline(char s[], int lim) { // lim sabemos que corresponde a MAXLINE
  int c, i;
  // En este caso, quitamos el 'i < lim' para que lea hasta el final de la linea 
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    // Ahora solo deberíamos guardar si hay espacio en el array
    // Recordemos que el array es de 1000 caracteres, lo cual significa que va del 0 al 999. 
    // Como en los proyectos que estoy haciendo, siempre le debemos restar 1 
    // para que no haya desbordamientos de memoria
    if (i < lim - 1) { // recordemos que lim es MAXLINE
      s[i] = c;
    }
  }

  // ya que hemos quitado la comprobacion i < lim, ahora debemos tener cuidado con estos bloques 
  // o daría pie al mismo error
  
  if (c == '\n') {
    if (i < lim -1) {
      s[i] = c;
    }
    ++i; // Hay que seguir sumando 1 a la i porque el salto de línea también cuenta como un caracter leído
  }

  if (i >= lim) {
    s[lim -1] = '\0';
  } else {
    s[i] = '\0';
  }


  return i;
}


// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[]) {
  int i;

  i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}


