#include <stdio.h>

int main(void)
{
  int lengths[10];
  int c, wl, i, j;

  wl = 0;

  for(i = 0; i < 10; ++i) {
    lengths[i] = 0;
  }

  /* Build up an array of word length frequencies */
  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (wl > 0) {
        lengths[wl > 10 ? 10 : wl - 1]++; // All words >10 chars will be counted as 10+
        wl = 0;
      }
    } else {
      wl++;
    }
  }

  for (i = 0; i < 10; ++i) {
    printf("%d:\t", i + 1);
    for(j = 0; j < lengths[i]; ++j) {
      putchar('X');
    }
    putchar('\n');
  }
}
