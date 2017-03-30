#include <ctype.h>
#include <stdio.h>
#define MAXOP 100 /* maximum number of args for an operator */

int calculator();
char push(char, char[]);
char pop(char[]);
void teststack(void);

int main(void)
{
  calculator();
}

/* calculator: returns the value of a sequence of reverse-polish ordered values and operations */
int calculator()
{
  char stack[MAXOP];
  stack[0] = MAXOP - 1; /* stack size (- 1 for the np) */
  stack[1] = 0; /* top of the stack */

  int i;
  for (i = 2; i < (MAXOP - 2); ++i)
    stack[i] = 0;

  char c, op2;

  while ((c = getchar()) != EOF) {

    if (isspace(c) && c != '\n')
      continue;

    if (c <= '9' && c >= '0') {
      push(c - '0', stack);
      continue;
    }

    switch (c) {
      case '+':
        push(pop(stack) + pop(stack), stack);
        break;
      case '-':
        op2 = pop(stack);
        push(pop(stack) - op2, stack);
        break;
      case '*':
        push(pop(stack) * pop(stack), stack);
        break;
      case '/':
        op2 = pop(stack);
        if (op2 != 0)
          push(pop(stack) / op2, stack);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop(stack);
        if (op2 != 0)
          push(pop(stack) % op2, stack);
        else
          printf("error: zero divisor\n");
        break;
      case '\n':
        printf("Out: %d\n", pop(stack));
        break;
      default:
        printf("error: unrecogrized character: %c\n", c);
        break; /* error */
    }
  }

  return 0; /* what should the return be? the calculated values should have all been output with printf() */

}

/* push: pushes a onto the top of a stack, returning the number of elements in the stack */
char push(char a, char stack[])
{
  if (stack[1] + 1 >= stack[0]) {
    printf("error: stack full, can't push %c\n", a);
    return 0;
  }

  stack[stack[1] + 2] = a; /* +2 because the first two elements are metadata */
  return ++stack[1];
}

/* pop: removes the topmost element of a stack, and returns that element */
char pop(char stack[])
{
  if (stack[1] < 1) {
    printf("error: stack already empty, can't pop\n");
    return 0;
  }

  return stack[--stack[1] + 2];
}
