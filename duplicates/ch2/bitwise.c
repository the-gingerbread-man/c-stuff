#include <stdio.h>

int setbits(int, int, int, int);
int invert(int, int, int);
int rightrot(int, int);

int main(void)
{
  // test setbits
  printf("setbits(0, 4, 3, ~0) expected 112, got %d\n", setbits(0, 4, 3, ~0));
  printf("setbits(~0, 4, 3, 0) expected 143, got %d\n", setbits(~0, 4, 3, 0));
  return 0;
}

/* return x with the n bits that begin at position p set to the rightmost n bits of y,
 * leaving the rightmost bits unchanged
 */
int setbits (int x, int p, int n, int y)
{
  int y_mask = ~0 << n;
  y = (y & ~y_mask) << p;
  
  int x_mask = ~0 << p ^ ~0 << p + n;
  x = x & x_mask;
  
  return x | y;
}

/* return x with the n bits that begin at position p inverted
 */
int invert (int x, int p, int n)
{
  int prefix = x & ~0 << p + n;
  int suffix = x ^ ~0 << n;

  x = x ^ prefix;
  x = x ^ suffix;
  return x | prefix | suffix;
}

/* return x rotated to the right by n positions
 * assumes 32-bit integers
 */
int rightrot(int x, int n)
{
  int tail = x ^ ~0 << n;

  x = x >> n;
  tail = tail << 32 - n;

  return x & tail;
}
