#include <stdio.h>
#define FALSE 0
#define TRUE 1

/* balanced-parens: checks that all opened parenthesis in a file are followed by a closing parenthesis.
    note: this includes parens anywhere in the file, including inside quoted strings and in comments.
  */
int main(void)
{
  int ch, openparens, balanced;

  openparens = 0;
  balanced = TRUE;

  while ((ch = getchar()) != EOF) {
    if (ch == '(')
      openparens++;
    else if (ch == ')' && openparens > 0)
      openparens--;
    else if (ch == ')')
      balanced = FALSE;
  }

  if (openparens != 0)
    balanced = FALSE;

  printf("%s", balanced ? "TRUE" : "FALSE");
  printf("\nOpen Parens:\t%d", openparens);

}
