
/* astrcpy: copies each character of ct to s, including '\0' pointer version */
char *astrcpy(char *s, char *ct)
{
  char *out = s;

  while ((*s++ = *ct++))
    ;
  return out;
}
