#include <stdio.h>
#include "astr.h"

int main(void)
{
  char h[20] = "Hello, ";
  char w[20] = "World!";
  char q[20] = "ld!";
  char f[20] = "old";
  // char e[20] = {}; /* initalize to zeros */

  // printf("e: %s\n", e);
  // astrcpy(e, h);
  // printf("e: %s\n", e);

  // printf("h: %s\n", h);
  // printf("--------------------\n");
  // astrcat(h, w);
  // printf("h: %s\n", h);

  printf("%d\n%d\n", astrend(w, q), astrend(q, f));
  return 1;
}
