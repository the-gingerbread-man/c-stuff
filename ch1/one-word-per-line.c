#include <stdio.h>

#define IN 0
#define OUT 1

/* seperates each word with a newline */
int main(void)
{
  int c, state;

  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN)
        putchar('\n');
      state = OUT;
    } else {
      putchar(c);
    }
  }
}
