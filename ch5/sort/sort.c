#include <stdio.h>
#include "sort.h"

int main(void)
{
  int a[10] = {6, 1, 7, 5, 3, 4, 9, 2, 8};

  int i;
  printf("Unsorted:  ");
  for (i = 0; i < 9; ++i)
    printf("%d ", a[i]);
  printf("\n");

  quicksort(a, a+8);
  printf("Sorted:    ");
  for (i = 0; i < 9; ++i)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}
