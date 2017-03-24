#include <stdio.h>

#define LOWER 0 // lower bound of tempature table
#define UPPER 300
#define STEP 20

int toCelsius(int fahr);

/* print Farenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main(void)
{
  int fahr;

  printf("F\tC\n----------\n");

  fahr = LOWER;
  while (fahr <= UPPER) {
    printf("%d\t%d\n", fahr, toCelsius(fahr));
    fahr = fahr + STEP;
  }
}

int toCelsius(int fahr)
{
  return 5 * (fahr - 32) / 9;
}
