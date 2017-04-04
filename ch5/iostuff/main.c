#include <stdio.h>
#include "iostuff.h"

int main(void)
{
  int i;

  while (getint(&i) != EOF) {
    printf("i:\t%d\n", i);
  }

  return 0;
}
