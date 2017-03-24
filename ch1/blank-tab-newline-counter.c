#include <stdio.h>

/* counts the number of spaces, tabs, and newlines in a file */
int main(void)
{
  int spaces, tabs, newlines;

  spaces = 0;
  tabs = 0;
  newlines = 0;

  int character;
  while ((character = getchar()) != EOF) {
    if (character == ' ')
      ++spaces;
    else if (character == '\t')
      ++tabs;
    else if (character == '\n')
      ++newlines;
  }

  printf("Spaces:\t\t%3d\n", spaces);
  printf("Tabs:\t\t%3d\n", tabs);
  printf("Newlines:\t%3d\n", newlines);
}
