#include <stdio.h>
#include <math.h>

int htoi(char digits[], int length, int base);

int main(void)
{
  char test[10] = "fffffff";

  printf("%d", htoi(test, 7, 16));
}

/* htoi: converts a string of hex digits to a long integer
    assumes BIG ENDIAN */
int htoi(char digits[], int length, int base)
{
  char digit;
  int dec, exp, place, placevalue;

  dec = exp = 0;

  while (length > 0) {
    place = pow(base, exp++);
    digit = digits[--length];

    printf("Dec:\t\t\t%d\n", dec);
    printf("Place:\t\t\t%d\n", place);
    printf("ASCII Digit:\t\t%d\t%c\n", digits[length], digit);

    if ('0' <= digit && digit <= '9') {
      dec += (digit - '0') * place;
      printf("0-9 Digit Value:\t%d\n", (digit - '0'));
      printf("Added:\t%d\n", (digit - '0') * place);
    }
    else if ('A' <= digit && digit <= 'F') {
      dec += ((digit - 'A') + 10) * place;
      printf("A-Z Digit Value:\t%d\n", (digit - 'A') + 10);
      printf("Added:\t%d\n", ((digit - 'A') + 10) * place);
    }
    else if ('a' <= digit && digit <= 'f') {
      dec += ((digit - 'a') + 10) * place;
      printf("a-z Digit Value:\t%d\n", (digit - 'a') + 10);
      printf("Added:\t%d\n", ((digit - 'a') + 10) * place);
    }

    printf("----------\n");
  }

  return dec;
}


