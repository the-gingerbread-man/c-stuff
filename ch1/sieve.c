#include <stdio.h>
#include <stdlib.h>

#define LIMIT 50000000 /*size of integers array*/

int main(void)
{
  unsigned long long int i,j;
  int *primes;
  int z = 1;

  primes = malloc(sizeof(int)*LIMIT);

  for (i=2;i<LIMIT;i++)
    primes[i]=1;

  for (i=2;i<LIMIT;i++)
    if (primes[i])
      for (j=i;i*j<LIMIT;j++)
        primes[i*j]=0;

  for (i=2;i<LIMIT;i++)
    if (primes[i]) {
      printf("%9d", i);
      putchar(((z++ % 6) == 0) ? '\n' : '\t');
    }
      // printf("%dth prime = %d\n",z++,i);

  return 0;
}
