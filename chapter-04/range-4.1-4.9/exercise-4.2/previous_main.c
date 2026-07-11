// Exercise 4.2: Extend atof to handle scientific notation of the form 123.45e-6 where the 
// floating-point number may be followed by e or E and an optionally signed exponent.


#include <ctype.h>


double atof(char s[]) {

  double val, power, result;
  int i, sign, exp_val, exp_sign, has_exp;

  has_exp = 0;

  for (i = 0; isspace(s[i]); i++) {
   ; 
  }

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') {
    i++;
  }

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }
  
  if (s[i] == '.') {
    i++;
  }
  
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  result = (sign * val) / power;


  if (s[i] == 'e' || s[i] == 'E') {
    has_exp = 1;
    i++;
  }

  if (has_exp == 1) {
    exp_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
      i++;
    }


    for (exp_val = 0; isdigit(s[i]); i++) {
      exp_val = 10 * exp_val + (s[i] - '0');
    }


    if (exp_sign == 1) {
      for (; exp_val > 0;) {
        result = result * 10.0;
        exp_val--; 
      }  
    } else {
      for (;exp_val > 0;) {
        result = result / 10.0;
        exp_val--;
      }
  
    /*
     As happened in a previous exercise, it's more readable with a while loop. I don't know why my 
     brain thinks of a for loop first haha!
     
     as an example: 

     while (exp_val > 0) {
      result = result * 10.0;
      exp_val--;
     }

     */
    }

  }

  return result;

}
