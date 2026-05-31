// Exercise 1.15: Rewrite the temperature conversion program of Section 1.2 
// to use a function for conversion


#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

// Prototipo: recibe un float que será fahr y devolverá un float que sera celsius
float converter(float fahr);

int main(void) {
  float fahr;
  
  printf("Conversion table\n");

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    printf("%3.0f %6.1f\n", fahr, converter(fahr));
  }

  return 0;

}

float converter(float fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}

/* Otra opción para la función:
  
float converter(float fahr)  {
  
  float n;
  
  n = (5.0 / 9.0) * (fahr - 32.0);

  return n;

}   */

// Cuál es más válida?
