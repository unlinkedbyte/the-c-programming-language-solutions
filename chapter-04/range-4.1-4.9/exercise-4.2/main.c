// Exercise 4.2: Extend atof to handle scientific notation of the form 123.45e-6 where the 
// floating-point number may be followed by e or E and an optionally signed exponent.

/* 
   This is the reviewed version of the previous code.
   
   After checking it and removing some redundant variables, I also modified 
   how the exponent is applied. Since most decimal fractions cannot be represented 
   exactly in binary floating-point (double), dividing or multiplying the result 
   by 10.0 multiple times inside a loop forces the computer to round the value 
   at each step, accumulating rounding errors. 
   
   Instead, calculating the total power first and performing a single arithmetic 
   operation at the end provides better precision. This is the corrected code:
*/


#include <ctype.h>

double atof(char s[]) {
  double val, power, result, exp_power;
  int i, sign, exp_val, exp_sign;

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
    i++;

    exp_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
      i++;
    }

    for (exp_val = 0; isdigit(s[i]); i++) {
      exp_val = 10 * exp_val + (s[i] - '0');
    }

    exp_power = 1.0;
    while (exp_val > 0) {
      exp_power *= 10.0;
      exp_val--;
    }

    if (exp_sign == 1) {
      result *= exp_power;
    } else {
      result /= exp_power;
    }
  }

  return result;
}

