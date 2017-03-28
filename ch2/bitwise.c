#import <stdio.h>
#import <math.h>

unsigned int cruddybitmask32(int n, int p);
unsigned int createbitmask32(int n, int p);
unsigned int setbits(unsigned int x, int n, int p, unsigned int y);
unsigned int invert(unsigned int x, int n, int p);
unsigned int rightrot(unsigned int x, int n);
int bitcount(unsigned int x);

int main(void)
{
  unsigned int test;

  // test = cruddybitmask32(1, 30); // -> 0x4
  // test = cruddybitmask32(1, 0);  // -> 0x80000000
  // test = cruddybitmask32(1, 4);  // -> 0x8000000
  // test = cruddybitmask32(3, 8);  // -> 0xe00000
  // test = cruddybitmask32(1, 31); // -> 0x1

  // test = createbitmask32(1, 30); // -> 0x4
  // test = createbitmask32(1, 0);  // -> 0x80000000
  // test = createbitmask32(1, 4);  // -> 0x8000000
  // test = createbitmask32(3, 8);  // -> 0xe00000
  // test = createbitmask32(1, 31); // -> 0x1
  // test = createbitmask32(2, 2); // -> 0x30000000

  // test = setbits(0xF0, 3, 27, 0x55); // -> 0xf4

  // test = rightrot(0xF, 3); // -> 0xe0000001

  test = bitcount(0xfa0); // -> 0x6

  return 0;
}

/* cruddybitmask32: creates a 32-bit mask with the n bits starting at bit (32 - p) set to 1 */
unsigned int cruddybitmask32(int n, int p)
{
  unsigned int mask, exponent, placevalue;

  mask = 0;
  exponent = 31 - (unsigned) p;

  while (n-- > 0) {
    placevalue = (unsigned) pow(2, exponent--);
    mask = mask | placevalue;
  }

  return mask;
}

/* reatebitmask32: creates a bitmask using left shifts, rather than the power function */
unsigned int createbitmask32(int n, int p)
{
  return ~(~0U << n) << p;
  // unsigned int mask;

  // mask = 0;
  // p = 31 - p;

  // while (n-- > 0)
  //   mask = mask | 1 << p--;

  // return mask;
}

/* setbits: set the n bits beginning at position p (big to small) to the rightmost n bits of y */
unsigned int setbits(unsigned int x, int n, int p, unsigned int y)
{
  unsigned int mask;
  mask = createbitmask32(n, p);

  y = y << (32 - n - p);
  y = y & mask;
  x = x & ~mask;

  return x | y;

}

/* invert: inverts the n bits beginning at position p */
unsigned int invert(unsigned int x, int n, int p)
{
  // cheating: return x ^ bettercreatebitmask32(n, p);
  return x ^ (~(~0U << n) << p);
}

/* rightrot: rotates the bits of x to the right by n positions */
unsigned int rightrot(unsigned int x, int n)
{
  // unsigned int rollover = x << (32 - n);
  // x = x >> n;
  // return rollover | x;

  return ((x << (32 - n)) | (x >> n));
}

/* bitcount: counts the number of 1 bits in x */
int bitcount(unsigned int x)
{
  int ones = 0;

  while (x != 0) {
    x &= (x - 1);
    ones++;
  }

  return ones;
}
