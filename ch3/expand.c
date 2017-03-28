#include <stdio.h>

void expand(char in[], char out[]);
void zeroout(char a[]);

int main(void)
{
  char testout[200];

  // expand("nothing to expand here", testout);
  zeroout(testout);

  // expand("a-z", testout);
  // zeroout(testout);

  // expand("a-d-f", testout);
  // zeroout(testout);

  // expand("-a-p", testout);
  // zeroout(testout);

  expand("a-z0-9", testout);
}

/* expand: takes in a string and copies it to out[], expanding sequences like a-z or 0-9 */
void expand(char in[], char out[])
{
  char c, i, o, start, end;

  i = o = 0;
  while ((c = in[i++]) != '\0') {
    if (c == '-') {
      start = in[i - 2]; // i has already been incremented
      end = in[i];
      if (start <= ' ') // Don't try to expand whitespace
        continue;

      while (start < (end - 1)) // the last character will be printed on its own
        out[o++] = ++start;
    } else {
      out[o++] = c;
    }
  }

  printf("In: %s  Out: %s\n", in, out);
}

/* zeroout: wipe the contents of a[] to all zeros */
void zeroout(char a[])
{
  int i = 0;

  while (a[i] != '\0')
    a[i++] = 0;
}
