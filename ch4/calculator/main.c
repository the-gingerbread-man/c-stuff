#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main(void)
{
  int type;
  double op2; /* used to store 2nd operand for non-commutative operators */
  char s[MAXOP]; /* raw characters (digits) of a single input value */

  while ((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s)); /* the calculator operates on doubles */
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(op2 / pop());
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0)
          push((double) ((long) op2 % (long) pop()));
        else
          printf("error: zero divisor\n");
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
      }
    }
    return 0;
}
