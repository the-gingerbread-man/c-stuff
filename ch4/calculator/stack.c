#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 /* maximum size of the calculator stack */

static double val[MAXVAL];
static int sp = 0;

/* push: pushes a onto the top of the calculator stack val[] */
void push(double a)
{
  if (sp < MAXVAL)
    val[sp++] = a;
  else
    printf("error: stack full, can't push %f\n", a);
}

/* pop: removes the topmost element of the calculator stack val[], and returns that element */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty, can't pop\n");
    return 0.0;
  }
}

/* print: returns the top element of the calculator stack val[] without popping it */
double print()
{
  if (sp > 0)
    return val[sp - 1];

  printf("error: stack empty, can't print\n");
  return 0.0;
}

/* duplicate: copies the top element of the calculator stack val[] and returns it */
double duplicate()
{
  if (sp > 0) {
    push(print());
    return print();
  }

  printf("error: stack empty, can't duplicate\n");
  return 0.0;
}

/* swap: swaps the top two elements of the calculator stack val[] */
void swap()
{
  double a, b;

  if (sp > 1) {
    a = pop();
    b = pop();
    push(a);
    push(b);
    return;
  }

  printf("error: stack has only %d elements, can't swap\n", sp);
}

/* clear: removes all elements from the calculator stack val[] */
void clear()
{
  while (sp > 0)
    pop();
}
