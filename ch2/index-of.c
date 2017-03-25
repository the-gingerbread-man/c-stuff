#include <stdio.h>

int indexof(char source[], char target);
int indexofany(char source[], char targets[]);
void testindexofany(void);

int main(void)
{
  testindexofany();
}

int indexof(char str[], char target)
{
  int i = 0;
  char c;

  while ((c = str[i++]) != '\0')
    if (c == target)
      return c;

  return -1;
}

int indexofany(char source[], char targets[])
{
  int sourceindex, targetindex;
  char sourcechar, targetchar;

  sourceindex = 0;
  while ((sourcechar = source[sourceindex++]) != '\0') {

    targetindex = 0;
    printf("SC:\t%c\tTC:\t%c\tSI:\t%d\tTI:\t%d\n", sourcechar, targetchar, sourceindex, targetindex);

    while ((targetchar = targets[targetindex++]) != '\0') {
      printf("SC:\t%c\tTC:\t%c\tSI:\t%d\tTI:\t%d\t*inner*\n", sourcechar, targetchar, sourceindex, targetindex);
      if (sourcechar == targetchar)
        return sourceindex - 1; // because it's incremented at the beginning of each outer loop iteration
    }
  }

  return -1;
}

void testindexofany(void)
{
  char source[113] = "Good Morning, Vietnam! Hey, this is not a test, THIS IS ROCK AND ROLL! Time to rock it from the delta to the DMZ!";
  char stuff[10] = "WWWWWWWWWW";
  char targets[3] = "DMZ";

  // expect 5 (not 68)
  printf("Index:\t%d", indexofany(source, targets));
}

