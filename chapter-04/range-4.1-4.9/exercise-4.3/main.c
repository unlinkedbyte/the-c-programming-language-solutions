// Exercise 4.3: Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.


#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>      /* for isdigit */

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100  /* max depth of val stack */
#define BUFSIZE 100 /* buffer size for ungetch */ 

int getop(char [], int);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
int bufp = 0;
char buf[BUFSIZE];
int sp = 0;
double val[MAXVAL];


/* reverse Polish calculator */

int main () {
  int type; 
  double op2, op1;
  char s[MAXOP];

  while ((type = getop(s, MAXOP)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0) {
        push(pop() / op2);
      } else {
        printf("error: zero divisor\n");
        exit(EXIT_FAILURE);
      }
      break;
    case '%':
      { // In C, when you create new local variables inside a case, you must wrap the case block
        // in curly braces {} so the compiler knows where the scope of those variables begins
        // and ends
        op1 = pop();
        op2 = pop();
        int divisor = (int)op1;
        int dividendo = (int)op2;

        if (divisor != 0) {
          push(dividendo % divisor);
        } else {
          fprintf(stderr, "error: modulus by zero after truncation\n");
          exit(EXIT_FAILURE);          
        }
      }
      break; 
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, can't push %g\n", f);
    exit(EXIT_FAILURE);  
  }
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty.\n");
    exit(EXIT_FAILURE);
  }
}



/* getop: get next operator or numeric operand */
int getop(char s[], int max_size) {
  int i, c, next;
  i = 0;

  while ((c = getch()) == ' ' || c == '\t') {
    ;
  }
  
  if (c == EOF) {
    return EOF;
  }

  s[i++] = c; 

  if (!isdigit(c) && c != '.' && c != '-') {
    s[i] = '\0';
    return c;
  }

  if (c == '-') {
    next = getch();
    
    if (!isdigit(next) && next != '.') {
      if (next != EOF) {
        ungetch(next);
      }
      s[i] = '\0'; // s[0] = '-', s[1] = '\0'
      return '-';
    }
    
    if (i < max_size - 1) {
      s[i++] = next;
      c = next;
    } else {
      fprintf(stderr, "error: operand too long.\n");
      exit(EXIT_FAILURE);
    }
  }

  if (isdigit(c)) {
    while ((next = getch()) != EOF && isdigit(next)) {
      if (i < max_size - 1) {
        s[i++] = next;
      } else {
        fprintf(stderr, "error: operand too long.\n");
        exit(EXIT_FAILURE);
      }
    }
    c = next;
  }
  
  if (c == '.') {
    if (i < max_size - 1) {
      s[i++] = c;
    } else {
      fprintf(stderr, "error: operand too long.\n");
      exit(EXIT_FAILURE);
    }

    while ((next = getch()) != EOF && isdigit(next)) { 
      if (i < max_size - 1) {
        s[i++] = next;
      } else {
        fprintf(stderr, "error: operand too long.\n");
        exit(EXIT_FAILURE);
      }
    }
    c = next;
  }

  if (i < max_size) {
    s[i] = '\0';
  } else {
    fprintf(stderr, "error: buffer overflow preventing null terminator.\n");
    exit(EXIT_FAILURE);
  }

  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}

int getch(void) {   /* get a (possibly pushed back) character */
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
    exit(EXIT_FAILURE);
  } else {
    buf[bufp++] = c;
  }
}

