
/* quicksort: sort the array of integers between left and right into increasing order */
void quicksort(int *left, int *right)
{
  int *i, *last;

  void swap(int *, int *);

  if (left >= right)
    return; /* base case */

  for (i = last = left; i <= right; i++)
    if (*i < *right) /* use *right as the pivot */
      swap(last++, i);

  swap(right, last); /* move the pivot to its correct position */
  quicksort(left, last - 1);
  quicksort(last+1, right);
}

/* swap: interchange *i and *j */
void swap(int *i, int *j)
{
  int temp;

  temp = *i;
  *i = *j;
  *j = temp;
}
