#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define OUT 0
#define IN 1

/* balanced-parens: checks that all opened parenthesis in a file are followed by a closing parenthesis.
    note: this includes parens anywhere in the file, including inside quoted strings and in comments.

    TODO: Create an array of "Errors" to output instead of just true|false
    TODO: Improve the analyzer to look for anything outside of braces, function and variable declarations, etc...
  */
int main(void)
{
  int ch, openparens, openbrackets, openbraces;
  char prev, singlequotestate, doublequotestate, commentstate, linecommentstate;

  prev = '\0';
  singlequotestate = doublequotestate = commentstate = linecommentstate = OUT;
  openparens = openbrackets = openbraces = 0;

  while ((ch = getchar()) != EOF) {

    if (prev == '/') {
      if (ch == '*')
        commentstate = IN;
      else if (ch == '/')
        linecommentstate = IN;
      prev = ch;
      continue;
    }

    if (commentstate == IN) {
      if (prev == '*' && ch == '/')
        commentstate = OUT;
      prev = ch;
      continue;
    }

    if (linecommentstate == IN) {
      if (ch == '\n')
        linecommentstate = OUT;
      prev = ch;
      continue;
    }

    if (singlequotestate == IN) {
      if (ch == '\'')
        singlequotestate = OUT;
      prev = ch;
      continue;
    }

    if (doublequotestate == IN) {
      if (ch == '\"')
        doublequotestate = OUT;
      prev = ch;
      continue;
    }

    switch(ch) {
      case '(':
        openparens++;
        break;
      case '[':
        openbrackets++;
        break;
      case '{':
        openbraces++;
        break;
      case ')':
        if (openparens <= 0)
          return FALSE;
        openparens--;
        break;
      case ']':
        if (openbrackets <= 0)
          return FALSE;
        openbrackets--;
        break;
      case '}':
        if (openbraces <= 0)
          return FALSE;
        openbraces--;
        break;
    }

    prev = ch;
  }

  if (singlequotestate || doublequotestate || commentstate || linecommentstate ||
      openparens || openbrackets || openbraces) {
    printf("FALSE");
    return FALSE;
  }
  else {
    printf("TRUE");
    return TRUE;
  }
}
