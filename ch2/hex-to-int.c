#include <stdio.h>
#include <math.h>

long htoi(char digits[], int length);

int main(void)
{
  char test[12] = "ffffffffffff";

  printf("%ld", htoi(test, 12));
  return 0;
}

/**
  * htoi: Converts a string of hex digits to a long integer
  *       Note: assumes BIG ENDIAN inputs
  * TODO: Add explicit '0x' checking and then ban all invalid inputs
  */
long htoi(char digits[], int length)
{
  char digit;
  int exp;
  long dec, place;

  dec = exp = 0;

  while (length > 0) {
    place = pow(16, exp++);
    digit = digits[--length];

    if ('0' <= digit && digit <= '9')
      dec += (digit - '0') * place;
    else if ('A' <= digit && digit <= 'F')
      dec += ((digit - 'A') + 10) * place;
    else if ('a' <= digit && digit <= 'f')
      dec += ((digit - 'a') + 10) * place;
  }

  return dec;
}
