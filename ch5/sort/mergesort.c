/* Merge Sort (incomplete) */

/* mergesort: */
void mergesort(int *left, int *right)
{
  if (right <= left)
    return;

  int sorted[right - left] = {};


}

/* mergesorted: combines two sorted integer arrays a and b into one sorted output array out */
/* FIXME: expects a and b to end with '\0' */
void mergesorted(int *a, int *b, int *out)
{
  int *i = out;
  while (*a != '\0' && *b != '\0')
    *i++ = (*a < *b) ? *a++ : *b++;

  while (*a != '\0')
    *i++ = *a++;
  while (*b != '\0')
    *i++ = *b++;
}
