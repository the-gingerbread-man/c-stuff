#include <stdio.h>

unsigned int setbits(unsigned int, int, int, unsigned int);
unsigned int invert(unsigned int, int, int);
int rightrot(int, int);

int main(void)
{
  // test setbits
  printf("setbits(x=73, p = 10, n = 3, y = 30)\nGot:\t%u\tExpected:\t841\n\n", setbits(73u, 10, 3, 30u));

  // test invert
  printf("invert(x=170, p=4, n=3)\nGot:\t%u\tExpected:\t164\n\n", invert(170u, 4, 3));
  
  // test rightrot

  
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
unsigned int invert (unsigned int x, int p, int n)
{
  unsigned int mask = ~0 << (p - n) ^ ~(~0 << p);

  unsigned int unaffected_part = x & mask;
  unsigned int inverted_part = ~x ^ mask;

  return unaffected_part | inverted_part;
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
