## Bitwise.c

### Setbits
Takes two unsigned ints (x and y) and coordinates p and n,
and sets the n bits of x starting at position p (counting from the right)
to the rightmost n bits of y.

Ex. setbits(x = 73u, p = 10, n = 3, y = 30u) (o = expected output)
x =  73 = 0000.0000.0000.0000.0000.0000.0100.1001
y =  30 = 0000.0000.0000.0000.0000.0000.0001.1110
o = 841 = 0000.0000.0000.0000.0000.0011.0100.1001
changed:                             ** *

Algorithm:
1. Create a mask for y to zero out all but the rightmost n bits by leftshifting ~0 (all 1s) by n,
   then taking the one's complement.
   Ex. n = 3 ~(1111.1111.1111.1111 << 3) = 0000.0000.0000.0111
2. Isolate the n significant bits of y by applying a bitwise AND and y-mask.
3. Left-shift y by (p - n) to move the significant bits to their final positons.
4. Create a mask for x to zero out the bits between position p and position (p - n).
   ** remember, bits are numbered from the left
   Accomplished by bitwise XORing two partial masks,
   the first by left-shifting ~0 by (p - n) to block out the bits greater than p,
   the second by taking the one's-complement of ~0 left-shifted by p to block out bits less than p.
   Ex. p = 10, n = 3 (the partial masks overlap only between bits p and (p - n))
   x-left-mask = 1111.1111.1111.1111.1111.1111.1000.0000
   x-rght-mask = 0000.0000.0000.0000.0000.0011.1111.1111
   x-mask(XOR) = 1111.1111.1111.1111.1111.1100.0111.1111
                                            ** *
5. Zero out the bits of x between p and (p - n) by applying a bitwise & and x-mask.
6. Return the bitwise OR of x and y.

### Invert
Takes one unsigned int (x) and returns x with the n bits beginning at position p inverted.

Ex: invert(170u, 4, 3) (o = expected output)
x = 1010.1010
o = 1010.0100
changed: ***

Algorithm:
note: (Can't just call setbits() because that will use the rightmost bits of y, not the same-position bits).
1. Create a mask for bits where p > bit-position > p - n
   i.e. p = 4, n = 2, mask = 1111.0011
2. Apply AND to x and the mask to get the unaffected part of x.
3. Apply XOR to the one's complement (inverse) of x to isolate the inverted part.
4. Combine the unaffected and inverted parts of x with OR, and return.

### Rightrot
Takes one unsigned int (x) and returns x with the bits rotated to the right n places.
Assumes 32-bit unsigned ints.

Ex. rightrot(15u, 2) (o = expected output)
x = 0000.0000.0000.0000.0000.0000.0000.1111
o = 1100.0000.0000.0000.0000.0000.0000.0011

Algorithm:
1. Get the "tail" by left-shifting x by 32 - n.
2. Rightshift x by n, then add the tail part back with a bitwise OR. Return.
