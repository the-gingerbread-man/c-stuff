#include <stdio.h>
#define MAXLINE 1000

void reverse(char line[], int len);
int getnextline(char line[], int maxline);

/* reverses each line of stdin and prints it to the console */
int main(void)
{
  char line[MAXLINE];
  int len;

  while((len = getnextline(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }
}

/* reverse: takes a character array and reverses it in place */
void reverse(char line[], int len)
{
  char swap;

  for (int i = 0; i < len / 2; ++i) {
    swap = line[i];
    line[i] = line[len - i - 1];
    line[len - i - 1] = swap;
  }
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
