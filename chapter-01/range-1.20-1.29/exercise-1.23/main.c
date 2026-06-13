// Exercise 1.23: Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments do not nest.

#include <stdio.h>

#define OUT 0
#define IN_STRING 1
#define IN_COMMENT 2
#define IN_BLOCK_COMMENT 3
#define IN_CHAR 4

int main(void) {

  int current, next, state, previous, escaped;

  state = OUT;
  previous = 0;
  next = 0;
  escaped = 0;

  while ((current = getchar()) != EOF) {
    
    if (state == OUT) {
      if (current == '"') {
        state = IN_STRING;
        putchar(current);
      } else if (current == '\'') {
        state = IN_CHAR;
        putchar(current);
      } else if (current == '/') {
        next = getchar();
        if (next == '/') {
          state = IN_COMMENT;
        } else if (next == '*') {
          state = IN_BLOCK_COMMENT;
        } else {
          putchar(current);
          if (next != EOF) {
            putchar(next); // Si el caracter siguiente no pertenece a un comentario, imprimimos ambos
          }

        }


      } else {
        putchar(current);
      }
    }

    /* En el programa, un mismo caracter que leemos con getchar() no puede estar en dos sitios a la 
     * vez. O procesamos código normal (OUT), o estamos dentro de una cadena (IN_STRING), o
     * estamos dentro de un comentario (IN_COMMENT / IN_BLOCK_COMMENT). Si usaramos if normales
     * uno detrás de otro, el procesador se vería obligado a evaluar todas las condiciones
     * para un mismo caracter. Incluso si el programa entra en el primer if porque el estado esta
     * a OUT, y realiza un cambio de estado ahí dentro, al salir de ese bloque saltaría directamente 
     * al segundo if a comprobarlo de nuevo. Esto podría provocar que las condiciones se pisen
     * y el programa actúe como si estuviera en dos estados al mismo milisegundo, corrompiendo el
     * flujo.
     * Es algo que quería dejar apuntado para mi. Eficiencia del procesador y exclusión mutua.
     * Es el motivo por el que usamos else if y no ifs despues del primer bloque. 
     */

    else if (state == IN_STRING) {
      putchar(current);
      if (escaped) {
        escaped = 0;
      } else if (current == '\\') {
        escaped = 1; // El siguiente caracter estará escapado
      } else if (current == '"') { // Comilla real de cierre
        state = OUT; // 
      }
    }
    
    else if (state == IN_COMMENT) {
      if (current == '\n') {
        putchar(current); // El salto de línea debe imprimirse para no juntar el código inferior
        state = OUT;
      }
    }

    // Aqui no usamos next = getchar() porque si el asterisco que comprobamos no es el último, 
    // nos comeríamos el caracter que viene detrás. Y si ese caracter resultaba ser el asterisco
    // real de cierre, seguiría borrando código, por eso necesitamos una nueva variable
    else if (state == IN_BLOCK_COMMENT) {
      if (current == '/' && previous == '*') {
        state = OUT;
      }
    
    }
    
    else if (state == IN_CHAR) {
      putchar(current);
      if (escaped) {
        escaped = 0;
      } else if (current == '\\') {
        escaped = 1;
      } else if (current == '\'') {
        state = OUT;
      }
    }
    

    previous = current; // guardaoms el caracter actual en el final de la vuelta para que en la
                          // siguiente sea el previo.
    

  }
     

  return 0;
}
