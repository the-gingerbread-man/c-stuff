
/**
  * strncmp: compares the first n digits of cs to ct
  * @return:
  *   <0 if cs < ct
  *    0 if cs == ct
  *   >0 if cs > ct
  */
int astrncmp(char *cs, char *ct, int n)
{
  while (--n && (*cs++ == *ct++))
    ; /* skip through equal characters */

  return ((n == 0)
          ? 0
          : (*--cs - *--ct));
}
