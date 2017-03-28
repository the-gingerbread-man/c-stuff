#import <stdio.h>

char lower(char c);

int main(void)
{
  char test;

  test = lower('P'); // -> p (112)
  test = lower('z'); // -> z (122)
  test = lower('A'); // -> a (97)
}

/* lower: takes an ASCII character and returns the lowercase version of that character */
char lower(char c)
{
  return ('A' <= c && c <= 'Z') ? c + ('a' - 'A') : c;
}
