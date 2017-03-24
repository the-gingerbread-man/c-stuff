#include <stdio.h>

int main(void)
{
  int c, f;
  int freqs[128];

  for(int i = 0; i < 128; ++i)
    freqs[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c < '~')
      freqs[c]++;
  }

  for (int j = 0; j < 128; ++j) {
    f = freqs[j];
    if (f > 0) {
      putchar(j);
      putchar('\t');
      for (int k = 0; k < f; ++k)
        putchar('X');
      putchar('\n');
    }
  }
}
