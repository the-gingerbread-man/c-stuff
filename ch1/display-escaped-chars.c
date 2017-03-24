#include <stdio.h>

int main(void)
{
  int nc;

  while ((nc = getchar()) != EOF) {
    switch(nc) {
      case '\t' :
        putchar('\\');
        putchar('t');
        break;
      case '\b' :
        putchar('\\');
        putchar('b');
        break;
      case '\\' :
        putchar('\\');
        putchar('\\');
        break;
      default :
        putchar(nc);
    }
  }
}
