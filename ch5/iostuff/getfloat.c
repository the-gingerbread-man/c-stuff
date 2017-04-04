#include <ctype.h>
#include "iostuff.h"

/** getfloat: reads a floating point number from stdin to *pn, returning the last character read */
int getfloat(double *pn)
{
  int c, sign, exp;

  while (isspace(c = getch()))
    ; /* skip leading whitespace */
  printf("%c\n", c); /* for debugging */
  if (!isdigit(c)
      && c != '+'
      && c != '-'
      && c != '.'
      && c != EOF) {
    ungetch(c); /* not a number found */
    printf("error: getfloat unexpected character: %c", c);
    return 0;
  }

  sign = (c == '-')
          ? -1
          : 1;

  if (c == '+' || c == '-') {
    int s = c;
    c = getch();

    if (isspace(c)) { /* found +/- followed by whitespace */
      ungetch(s); /* push the +/- back into the input buffer */
      return 0; /* ignore (drop) the whitespace */
    }
  }

  *pn = 0;
  exp = 1;
  if (c != '.') {
    do {
      *pn = *pn * 10 + (c - '0');
    } while (isdigit(c = getch()));
  } else {
    c = getch();
  }
  while (isdigit(c = getch())) {
    *pn = *pn * 10 + (c - '0');
    exp *= 10;
  }
  /* TODO: add handling for scientific notation in the form 3.5e4 */
  *pn *= sign;
  *pn = (*pn / exp);

  if (c != EOF)
    ungetch(c);

  return c;
}
