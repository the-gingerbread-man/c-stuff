#include <stdio.h>
#include "iostuff.h"

int main(void)
{
  double i;

  while (getfloat(&i) != EOF) {
    printf("i:\t%f\n", i);
  }
  printf("main is done, i: %f", i);
  return 0;
}
