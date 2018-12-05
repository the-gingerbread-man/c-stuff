#include <stdio.h>

unsigned int setbits(unsigned int, int, int, unsigned int);
int invert(int, int, int);
int rightrot(int, int);

int main(void)
{
  // test setbits
  printf("setbits(x=73, p = 10, n = 3, y = 30)\nGot:\t%u\tExpected:\t841\n", setbits(73u, 10, 3, 30u));
  return 0;
}

/* return x with the n bits that begin at position p set to the rightmost n bits of y,
 * leaving the rightmost bits unchanged
 */
unsigned int setbits (unsigned int x, int p, int n, unsigned int y)
{
  unsigned int y_mask = ~(~0 << n);
  y = (y & y_mask) << p - n;
  
  unsigned int x_mask = ~0 << p - n ^ ~(~0 << p);
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
