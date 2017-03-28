#import <stdio.h>
#import <math.h>

unsigned int createbitmask32(int n, int p);

int main(void)
{
  unsigned int test;

  test = createbitmask32(1, 30); // -> 0x4
  test = createbitmask32(1, 0);  // -> 0x80000000
  test = createbitmask32(1, 4);  // -> 0x8000000
  test = createbitmask32(3, 8);  // -> 0xe00000

  return 0;
}

/* createbitmask32: creates a 32-bit mask with the n bits starting at bit (32 - p) set to 1 */
unsigned int createbitmask32(int n, int p)
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
