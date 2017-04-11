#include <stdio.h>
#include "astr.h"

/**
  * astrcat: re-implements strcat from <string.h>
  *          appends each character of b onto the end of a
  */
void astrcat(char *a, char *b)
{
  // while (*a++)
  //   ; /* skip to the end of  a */
  // a--;
  // while (*a++ = *b++)
  //   ; /* append each character in b to the end of a */

  while (*a++)
    ; /* skip to the end of a */
  a--;
  astrcpy(a, b);

}
