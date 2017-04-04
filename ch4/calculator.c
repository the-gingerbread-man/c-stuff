#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100 /* maximum size of the input buffer */
#define MAXOP 100 /* maximum number of args for an operator */
#define MAXVAL 100 /* total size of the calculator stack */
#define NUMBER '0' /* type identifier for getop() and main() */

int getop(char []);

char getch(void);
void ungetch(char);

void push(double);
double pop();

double print();
double duplicate();
void swap();
void clear();

char buf[BUFSIZE]; /* input buffer stack */
int bufp = 0; /* next free stack position */

double val[MAXVAL]; /* calculator stack */
int sp = 0; /* next free stack position */

/* reverse polish calculator */
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

/* getop: reads the next character or numeric operand into s[]
    and returns it, or NUMBER if it is a number */
int getop(char s[])
{
  int i, c;

  // while ((s[0] = c = getch()) == ' ' || c == '\t')
  //   ; /* ignore blanks and tabs */

  do { /* ignore blanks and tabs */
    s[0] = c = getch();
  } while (c == ' ' || c == '\t');

  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-' && c != 'e' && c != 'E')
    return c; /* not a number or part of a number */

  i = 0;
  if (c == '-') {
    if (isdigit(c = getch())) { /* negative number */
      s[++i] = c;
    } else { /* minus operator */
      ungetch(c);
      return '-';
    }
  }

  if (isdigit(c)) /* collect integer part (plus the character the loop fails on, most likely ' ') */
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == 'e' || c == 'E') /* collect exponent */
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';

  if (c != EOF)
    ungetch(c); /* the character the while condition failed on */

  printf("%s\t%f\n", s, atof(s)); /* for debugging */
  return NUMBER;
}

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
