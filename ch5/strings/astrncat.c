
char *astrncat(char *s, char *ct, int n)
{
  char *out = s;

  while (*s++)
    ;
  s--;

  while (n-- && (*s++ = *ct++))
    ;

  return out;
}
