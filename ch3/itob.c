#include <stdio.h>
#include <string.h>

void itob(int n, int base, char s[]);

int main(void)
{
  char testout[100];

  itob(300, 2, testout);
  printf("%s", testout);
}

void itob(int n, int base, char s[])
{
  int i, sign;

  if ((sign = n) < 0)
    n = -n;

  i = 0;
  do {
    s[i++] = n % base + '0'; // This needs to be modified for bases >10
  } while ((n /= base) > 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';

  // strrev(s);
}
