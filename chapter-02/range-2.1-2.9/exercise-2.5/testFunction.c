#include <stdio.h>

int any(char s1[], char s2[]) {

  int i, k;

  for (i = 0; s1[i] != '\0'; i++) {
    for (k = 0; s2[k] != '\0'; k++) {
      if (s1[i] == s2[k]) {
        return i;
      }
    }
  }

  return -1;
}

int main(void) {
  char texto1[] = "programación";
  char texto2[] = "Bajo nivel en C";
  int pos1 = any(texto1, texto2);
  
  printf("Prueba 1 -> s1: '%s'\n2: '%s'\n", texto1, texto2);
  printf("Resultado: la primera coincidencia está en el índice: %d\n\n", pos1);

  char texto3[] = "bandera";
  char texto4[] = "pisto";
  int pos2 = any(texto3, texto4);
  printf("Prueba 2 -> s1: '%s'\n2: '%s'\n", texto3, texto4);
  printf("Resultado: %d (no hay coincidencias)\n", pos2);

  return 0;
}
