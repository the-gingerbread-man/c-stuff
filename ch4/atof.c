#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main(void)
{
  char t1[5] = "30"; // -> 30
  char t2[5] = "30."; // 30
  char t3[5] = "0.30"; // 0.3
  char t4[5] = ".30"; // 0.3
  char t5[5] = "3e1"; // 30
  char t6[6] = "3.0e1"; // 30
  char t7[5] = "e1"; // -> 0, perhaps it should give 10 instead?
  char t8[5] = "3e-1"; // -> 0.3
  char t9[5] = "-3e3"; // -> -3000

  printf("1In: %s\tOut:%f\n", t1, atof(t1));
  printf("2In: %s\tOut:%f\n", t2, atof(t2));
  printf("3In: %s\tOut:%f\n", t3, atof(t3));
  printf("4In: %s\tOut:%f\n", t4, atof(t4));
  printf("5In: %s\tOut:%f\n", t5, atof(t5));
  printf("6In: %s\tOut:%f\n", t6, atof(t6));
  printf("7In: %s\tOut:%f\n", t7, atof(t7));
  printf("8In: %s\tOut:%f\n", t8, atof(t8));
  printf("9In: %s\tOut:%f\n", t9, atof(t9));
}

/* atof: converts a string in the form of ([+-])?([0-9]+)(\.[0-9]*)?([eE][0-9]+)?
    to a double in base 10 */
double atof(char s[])
{
  double val;
  int i, sign, power, exp, expsign;

  for (i = 0; isspace(s[i]); i++)
    ; /* skip whitespace padding on the left */

  sign = (s[i] == '-' ? -1 : 1);

  if (s[i] == '-' || s[i] == '+')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;
  for (power = 0; isdigit(s[i]); i++) {
    val = 10 * val + (s[i] - '0');
    power--;
  }

  if (s[i] == 'e' || s[i] == 'E') /* this would be a great use case for recursion, but I don't yet know how to slice an array */
    i++;
  expsign = (s[i] == '-' ? -1 : 1);
  if (s[i] == '-' || s[i] == '+')
    i++;
  for (exp = 0; isdigit(s[i]); i++) /* seperate variables are necessary unless we know how many places are in the exponent */
    exp = 10 * exp + (s[i] - '0');
  exp *= expsign;
  exp += power;

  val *= sign;

  return val * pow(10, exp);
}
