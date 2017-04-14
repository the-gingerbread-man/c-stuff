
/* copies the first n characters in ct to string s, returns s */
char *astrncpy(char *s, char *ct, int n)
{
  char *out = s;
  while (n-- && (*s++ = *ct++))
    ;
  return out;
}
