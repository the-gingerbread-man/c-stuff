#include <stdio.h>

#define LOWER 0
#define UPPER 100
#define STEP 10

int main(void)
{
  float celsius, fahr;

  printf("%3c\t%3c\n-----------\n", 'C', 'F');

  celsius = LOWER;
  while (celsius <= UPPER) {
    fahr = (9.0 / 5.0) * celsius + 32;
    printf("%3.0f\t%3.0f\n", celsius, fahr);
    celsius += STEP;
  }
}
