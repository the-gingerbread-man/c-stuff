#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/* astrend: returns 1 if string q is found at the end of string s, else returns 0 */
int astrend(char *s, char *q)
{
  s += strlen(s) - strlen(q); /* does not handle cases where q is longer than s */

  while (*s != '\0')
    if (*s++ != *q++)
      return FALSE;

  return TRUE;
}
