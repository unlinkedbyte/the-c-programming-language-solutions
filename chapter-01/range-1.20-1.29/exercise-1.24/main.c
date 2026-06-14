// Exercise 1.24: Write a program to chech a C program for rudimentary syntax errors like unbalanced
// parentheses, brackets and braces. Don't forget about quotes, both single and double, escape
// sequences and comments. (This program is hard if you do it in full generality).

#include <stdio.h>

#define OUT 0
#define IN_STRING 1
#define IN_COMMENT 2
#define IN_BLOCK_COMMENT 3
#define IN_CHAR 4

int main(void) {

  int current, next, state, tope, escaped, previous;
  char pila[100];

  state = OUT;
  tope = 0;

 
  previous = 0; // Lo seguimos necesitando para detectar */ en IN_BLOCK_COMMENT
  escaped = 0; // lo seguimos necesitando para IN_STRING e IN_CHAR
  next = 0; // lo seguimos necesitando para detectar /* y // 



  while ((current = getchar()) != EOF) {

    
    if (state == OUT) {
      if (current == '(' || current == '[' || current == '{') {
        if (tope >= 100) {
          printf("[-] Error: too many nesting levels\n");
          return 1;
        }
      
        pila[tope++] = current;
      

      } else if (current == ')' || current == ']' || current == '}') {
        if (tope == 0) {
          printf("[-] Error: closing symbol '%c' without opening\n", current); 
          return 1;
        }

        char ultimo = pila[--tope]; // restamos uno para volver al último elemento real, despues lo comprobamos
        

        if ((ultimo == '(' && current != ')') || (ultimo == '[' && current != ']') || (ultimo == '{' && current != '}')) {
          printf("[-] Error: expected closing for '%c' but found '%c'\n", ultimo, current);
          return 1;
        }


      } else if (current == '"') {
        state = IN_STRING;
      } else if (current == '\'') {
        state = IN_CHAR;
      } else if (current == '/') {
        next = getchar();
        if (next == '/') {
          state = IN_COMMENT;
        } else if (next == '*') {
          state = IN_BLOCK_COMMENT;
          current = '\0';
        } else if (next != EOF) {
          ungetc(next, stdin); 
          /* ungetc() es una función de la librería de stdio.h que no nos ha enseñado el libro todavía
           * El problema de next es que se adelanta a ver el "futuro", por lo que podríamos perder
           * ciertos parentésis abiertos en ciertas declaraciones. Un ejemplo sería:
           * int total = a / (b + c);
           * */
        } else {
          printf("[-] Error: trailing '/' at te end of file\n");
          return 1;
        }

      } 


    }  




    else if (state == IN_STRING) {
      if (escaped) {
        escaped = 0;
      } else if (current == '\\') {
        escaped = 1;
      } else if (current == '"') {
        state = OUT;
      }
    }
    

    else if (state == IN_COMMENT) {
      if (current == '\n') {
        state = OUT;
      } 
    }


    else if (state == IN_BLOCK_COMMENT) {
      if (current == '/' && previous == '*') {
        state = OUT;
        current = '\0';
      }
    }
    

    else if (state == IN_CHAR) {
      if (escaped) {
        escaped = 0;
      } else if (current == '\\') {
        escaped = 1;
      } else if (current == '\'') {
        state = OUT;
      }
    }
    
    previous = current; 

  }

  // VALIDACIÓN DE ESTADOS AL LLEGAR A EOF
  if (state == IN_BLOCK_COMMENT) {
    printf("[-] Error: block comment '/*' was never closed\n");
    return 1;
  }
  if (state == IN_STRING) {
    printf("[-] Error: string literal '\"' was never closed\n");
    return 1;
  }
  if (state == IN_CHAR) {
    printf("[-] Error: char literal '\'' was never closed\n");
    return 1;
  }



  if (tope > 0) {
    printf("[-] Error: '%c' was never closed\n", pila[tope - 1]); // tope siempre apunta a la siguiente posición libre. Por eso hay que restarle una, porque si no leeriamos una posición vacía. 
    return 1;
  }

  return 0;
}
