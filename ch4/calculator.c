#include <ctype.h>
#include <stdio.h>
#define MAXLINE 40

int calculator();
char push(char a, char stack[]);
char pop(char stack[]);
void teststack(void);

int main(void)
{
  calculator();
}

/* calculator: returns the value of a sequence of reverse-polish ordered values and operations */
int calculator()
{
  char stack[MAXLINE];
  stack[0] = MAXLINE - 1; /* stack size (- 1 for the np) */
  stack[1] = 0; /* top of the stack */

  int i;
  for (i = 2; i < (MAXLINE - 2); ++i)
    stack[i] = 0;

  char c;

  // printf("Top:\t%c\n", stack[stack[1] + 1]);
  // printf("T:\t%d\n", stack[1]);
  // push(1, stack);
  // push(2, stack);
  // push(3, stack);
  // printf("Pop:\t%d\n", pop(stack));
  // printf("Pop:\t%d\n", pop(stack));
  // printf("T:\t%d\n", stack[1] + 2);
  // printf("Top:\t%c\n", stack[stack[1] + 1]);
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
        push(pop(stack) - pop(stack), stack);
        break;
      case '*':
        push(pop(stack) * pop(stack), stack);
        break;
      case '/':
        push(pop(stack) / pop(stack), stack);
        break;
      case '%':
        push(pop(stack) % pop(stack), stack);
        break;
      case '\n':
        printf("Out: %d\n", pop(stack));
        break;
      default:
        printf("Unrecogrized character: %c\n", c);
        break; /* error */
    }
  }

  return 0; /* what should the return be? the calculated values should have all been output with printf() */

}

/* push: pushes a onto the top of a stack, returning the number of elements in the stack */
char push(char a, char stack[])
{
  if (stack[1] + 1 >= stack[0]) /* Error: stack overflow */
    return '\0';

  stack[stack[1] + 2] = a; /* +2 because the first two elements are metadata */
  return ++stack[1];
}

/* pop: removes the topmost element of a stack, and returns that element */
char pop(char stack[])
{
  if (stack[1] < 1) /* Error: stack is empty */
    return '\0';

  return stack[--stack[1] + 2];
}

/* teststack: perform tests on the push and pop functions */
void teststack(void)
{
  char ts[13];
  ts[0] = 12; /* size, not including null terminator */
  ts[1] = 0; /* top */

  int i;
  for (i = 2; i < 12; ++i)
    ts[i] = 0;

  push('a', ts);
  push('b', ts);
  push('c', ts);
  push('d', ts);
  push('f', ts);
  pop(ts);
  pop(ts);
  push('x', ts);
  push('y', ts);
  pop(ts);
  push('z', ts);

  printf("ts:\t%s\n", ts); // -> "  abcxz"
}
