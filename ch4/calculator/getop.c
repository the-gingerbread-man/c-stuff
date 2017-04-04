#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define BUFSIZE 100 /* input buffer size */

static char buf[BUFSIZE];
static int bufp = 0;

static char getch()
{
  return (bufp > 0
            ? buf[--bufp]
            : getchar());
}

static void ungetch(char c)
{
  if (bufp >= BUFSIZE)
    printf("error: ungetch input buffer overflow\n");
  else
    buf[bufp++] = c;
}

/** getop: reads the next character or numeric operand into s[]
  *        and returns it, or NUMBER if it is a number
  */
int getop(char s[])
{
  int i, c;

  do { /* ignore blanks and tabs */
    s[0] = c = getch();
  } while (c == ' ' || c == '\t');

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-' && c != 'e' && c != 'E')
    return c; /* not a number or part of a number */

  i = 0;
  if (c == '-') {
    if (isdigit(c = getch())) { /* negative number */
      s[++i] = c;
    } else { /* minus operator */
      ungetch(c);
      return '-';
    }
  }

  if (isdigit(c)) /* collect integer part (plus the character the loop fails on, most likely ' ') */
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == 'e' || c == 'E') /* collect exponent */
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';

  if (c != EOF)
    ungetch(c); /* the character the while condition failed on */

  return NUMBER;
}
