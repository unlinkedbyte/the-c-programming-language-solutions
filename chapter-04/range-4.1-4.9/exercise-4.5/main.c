// Exercise 4.5: Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B,
// section 4.


#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>      /* for isdigit */
#include <math.h>
#include <string.h>
#include <limits.h>


#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100  /* max depth of val stack */
#define BUFSIZE 100 /* buffer size for ungetch */ 
#define NAME 'n'

int getop(char [], int);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
int bufp = 0;
char buf[BUFSIZE];
int sp = 0;
double val[MAXVAL];
void print_top(void);
void duplicate_top(void);
void clear_stack(void);

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
      { 
        op2 = pop();
        
        if (op2 == 0.0) {
          fprintf(stderr, "error: modulus by zero\n");
          exit(EXIT_FAILURE);          
        }

        double op1 = pop(); 

        if (op1 < INT_MIN || op1 > INT_MAX || op2 < INT_MIN || op2 > INT_MAX) {
          fprintf(stderr, "error: operands out of integer range for modulus\n");
          exit(EXIT_FAILURE);
        }

        int divisor = (int)op2;
        int dividendo = (int)op1;

        push(dividendo % divisor);
      }
      break; 
    case 'p':
      print_top();
      break;
    case 'd':
      duplicate_top();
      break;
    case 's':
      op1 = pop();
      op2 = pop();
      push(op2);
      push(op1);
      break;
    case 'c':
      clear_stack();
      break;
    case NAME:
      if (strcmp(s, "sin") == 0) {
        push(sin(pop()));
      } else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
      } else if (strcmp(s, "exp") == 0) {
        push(exp(pop()));
      } else {
        printf("error: unknown function %s\n", s);
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
  
  if(islower(c)) {
    while ((next = getch()) != EOF && islower(next)) {
      if (i < max_size - 1) {
        s[i++] = next;
      } else {
        fprintf(stderr, "error: function name too long.\n");
        exit(EXIT_FAILURE);
      }
    }

    s[i] = '\0';

    if (next != EOF) { ungetch(next); }
    return NAME;
  }

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

void print_top(void) {
  if (sp > 0) {
    printf("top element: %g\n", val[sp - 1]);
  } else {
    fprintf(stderr, "error: stack empty, can't print\n");
  }
}

void duplicate_top(void) {
  if (sp > 0) {
    push(val[sp - 1]);
  } else {
    fprintf(stderr, "error: stack empty, can't duplicate\n");
  }
}

void clear_stack(void) {
  sp = 0;
}
