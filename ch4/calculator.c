#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100
#define MAXOP 100 /* maximum number of args for an operator */
#define MAXVAL 100
#define NUMBER '0'

int getop(char []);

char getch(void);
void ungetch(char);

void push(double);
double pop();

char buf[BUFSIZE];
int bufp = 0;

double val[MAXVAL];
int sp = 0; /* next free stack position */

int main(void)
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
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
          push((int) op2 % (int) pop());
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

/* getch: gets the next character from the buffer, or, if it is empty, the next character from stdin */
char getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back into input buffer */
void ungetch(char c)
{
  if (bufp >= BUFSIZE)
    printf("error: ungetch input buffer overflow\n");
  else
    buf[bufp++] = c;
}

/* getop: gets the next input character or numeric operand */
int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ; /* ignore spaces and tabs */

  s[1] = '\0';

  if (!isdigit(c) && c != '.')
    return c; /* not a number */
  i = 0;

  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.') /* collect fraction part */
      while (isdigit(s[++i] = c = getch()))
        ;

  s[i] = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}

/* push: pushes a onto the top of the stack */
void push(double a)
{
  if (sp < MAXVAL)
    val[sp++] = a;
  else
    printf("error: stack full, can't push %f\n", a);
}

/* pop: removes the topmost element of the stack, and returns that element */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty, can't pop\n");
    return 0.0;
  }
}
