// Exercise 1.19: Write a function reverse(s) that reverses the character string s. 
// Use it to write a program that reverses its input a line at a time. 

#include <stdio.h>
#define MAXLINE 1000 // maximum input line size

int my_getline(char line[], int maxline);
void reverse(char s[]);

// print longest input line

int main(void) {
  int len; // current line length
  char line[MAXLINE]; // current input line
  int i;

  while ((len = my_getline(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
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

void reverse(char s[]) {
    
  int i, j;
  char temp;
  
  i = j = 0;
  
  while (s[j] != '\0') {
    ++j;
  }
  
  --j;
  if (s[j] == '\n') {
    --j;
  } 

  while (i < j) {
    temp = s[i]; // guardamos el byte de la derecha en temp
    s[i] = s[j]; // Copiamos el byte de la derecha en la izquierda
    s[j] = temp; // Ahora le asignamos lo que había guardado temp a j.
    
    ++i;
    --j;
  }
}
