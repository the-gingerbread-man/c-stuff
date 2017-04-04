#include <stdio.h>
#include "iostuff.h"

static char buf[BUFSIZE];
static int bp;

/** getch: reads one character from the input buffer, or from stdin if it's empty */
char getch(void)
{
  return (bp > 0)
            ? buf[--bp]
            : getchar();
}

/** ungetch: puts one character onto the input buffer */
void ungetch(char c)
{
  if (bp >= BUFSIZE)
    printf("error: ungetch can't put %c, input buffer full", c);

  buf[bp++] = c;
}
