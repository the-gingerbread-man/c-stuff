#include <stdio.h>

/* removes space characters at the beginning of the file
  and excess (>1) spaces between words */
main()
{
  int character, lastWasSpace;

  lastWasSpace = 1;  // remove any spaces at the start of the file

  while ((character = getchar()) != EOF) {
    if (character != ' ' || !lastWasSpace) {
      putchar(character);
    }

    lastWasSpace = (character == ' ') ? 1 : 0;
  }
}
