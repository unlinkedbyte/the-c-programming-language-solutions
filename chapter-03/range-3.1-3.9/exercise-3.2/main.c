// Exercise 3.2: Write a function escape(s,t) that converts characters like newline and tab into 
// visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a 
// function for the other direction as well, converting escape sequences into the real characters.

void escape(char s[],char t[]) {
  int i, j;
  
  j = i = 0;

  while (t[i] != '\0') {
    switch (t[i]) {
      case '\n':
        s[j] = '\\';
        j++;
        s[j] = 'n';
        j++;
        break;
      case '\t':
        s[j] = '\\';
        j++;
        s[j] = 't';
        j++;
        break;
      default:
        s[j] = t[i];
        j++;
        break;
    }

    i++;

  }

  s[j] = '\0';
}


void unescape(char s[], char t[]) {
  
  int i, j;

  j = i = 0;

  while (t[i] != '\0') {
    switch (t[i]) {
      case '\\':
        if (t[i+1] == 'n') {
          s[j] = '\n';
          j++;
          i++;
        } else if (t[i+1] == 't') {
          s[j] = '\t';
          j++;
          i++;
        } else {
          s[j] = '\\';
          j++;
        }
        break;
      default:
        s[j] = t[i];
        j++;
    }

    i++;
  
  }

  s[j] = '\0'; 

}
