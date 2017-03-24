#include <stdio.h>
#define MAXLINE 1000  /* maximum input line length */

int getnextline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void)
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getnextline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) /* there was a line */
    printf("%s", longest);
  return 0;
}

/* getnextline: reads one line from stdin, copies each character to s, and returns the length of the line */
int getnextline(char s[], int lim)
{
  int c, i;

  for (i=0; i < lim-1 && (c = getchar())!=EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: copies the contents of one char[] to another. assumes the output is large enough. */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
