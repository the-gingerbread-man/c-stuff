
/**
  * astrcat: re-implements strcat from <string.h>
  *          appends each character of ct onto the end of s
  *
  * returns a pointer to the beginning of the full concatinated string
  */
char *astrcat(char *s, char *ct)
{
  char *out = s;

  while (*s++)
    ; /* skip to the end of  a */
  s--; /* back up so that ct[0] overwrites the old null terminator of s */
  while ((*s++ = *ct++))
    ; /* append each character in b to the end of a */

  return out;
}
