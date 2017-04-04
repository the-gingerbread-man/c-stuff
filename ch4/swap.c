#include <stdio.h>

#define swap(type, a, b)\
          type s = a;\
          a = b;\
          b = s;

int main(void)
{
  char x = 'A';
  char y = 'Z';

  printf("%c\t%c\n", x, y); /* -> A Z */
  swap(char, x, y) /* semicolon is in the macro, right */
  printf("%c\t%c\n", x, y); /* -> Z A */
}
