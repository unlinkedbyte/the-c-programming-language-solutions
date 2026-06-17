// Exercise 2.4: Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that
// matches any character in the string s2.

void squeezev2(char s1[], char s2[]) {

  int i, j, k, encontrado;
  
  j = 0; 

  for (i = 0; s1[i] != '\0'; i++) {
    encontrado = 0;
    for (k = 0; s2[k] != '\0' && encontrado == 0; k++) { // Hemos implementado aqui esta segunda
                                                         // comprobación con encontrado == 0 por si
                                                         // s1 tuviera un array de 10 bytes(caracteres)
                                                         // y s2 tuviera uno de 1000 por ejemplo. 
                                                         // Es para que no lea información de más, 
                                                         // para optimizarlo
      if (s1[i] == s2[k]) {
        encontrado = 1;
      }
    }
    
    if (encontrado == 0) {
      s1[j++] = s1[i];
    }

  }
  
  s1[j] = '\0';

}
