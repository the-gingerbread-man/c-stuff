#include <ctype.h>
#include "iostuff.h"

/** getint: reads one signed integer from stdin and writes it to *pn
  *         returns the last character read, i.e. the one isdigit(c) failed on
  */
int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch()))
    ; /* ignore leading whitespace */

  if (!isdigit(c)
      && c != EOF
      && c != '+'
      && c != '-') {
    ungetch(c);
    return 0; /* not a number found */
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

  for (*pn = 0; isdigit(c); c = getch()) { /* add value of digits to *pn */
    *pn = *pn * 10 + (c - '0');
  }

  *pn *= sign;

  if (c != EOF)
    ungetch(c);

  return c;
}
