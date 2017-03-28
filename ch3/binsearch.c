#import <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
  // stuff
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = (n - 1);
  mid = (low + high) / 2;

  while (low <= high) {
    if (x < v[mid])
      high = mid + 1;
    else if (x > v[mid])
      low = mid + 1;
  }

  return x == mid ? mid : -1;
}
