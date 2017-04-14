#include <stdio.h>
#include "astr.h"

int main(void)
{
  /* test cases */
  char hello[20] = "Hello, ";
  char world[20] = "World!";
  char helend[20] = "o, ";
  char nhelend[20] = "o. ";
  char cmphello[20] = "Helooo?";

  // printf("astrcat:\t%s\n", astrcat(hello, world)); // -> "Hello, World!"
  // printf("astrncat:\t%s\n", astrncat(hello, world, 3)); // -> "Hello, Wor"

  // printf("astrcpy:\t%s\n", astrcpy(hello, world)); // -> "World!"
  // printf("astrncpy:\t%s\n", astrncpy(hello, world, 3)); // -> "Worlo, "

  // printf("astrend:\t%d\n", astrend(hello, helend)); // -> 1
  // printf("astrend:\t%d\n", astrend(hello, nhelend)); // -> 0

  // printf("astrncmp:\t%d\n", astrncmp(hello, cmphello, 3)); // -> 0
  // printf("astrncmp:\t%d\n", astrncmp(hello, cmphello, 6)); // -> (not zero)

  return 1;
}
