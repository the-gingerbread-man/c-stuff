#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main(void)
{
  int c, state;

  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c > 32) { /* not whitespace */
      state = IN;
      putchar(c);
    } else if (state == IN) {
      putchar ('\n');
      state = OUT;
    }
  }
}
