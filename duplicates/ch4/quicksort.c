#include <stdio.h>

void qsort(int[], int, int);
void swap(int[], int, int);

int main(void)
{
    /* test quicksort here */

    int test1[10] = {9, 1, 3, 4, 2, 5, 8, 7, 0, 6};
	
    qsort(test1, 0, 9);

    for(int i = 0; i < 10; i++)
	printf(" %d ", test1[i]);

    return 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int pivot, l, r;

    if (left >= right)
	return;          /* don't sort arrays < 2 elements */
    
    pivot = left + ((right - left) / 2);
    l = left;
    r = right;

    for(;;) {
	while (l < r && v[l] < v[pivot])
	    l++;

	while (l < r && v[r] > v[pivot])
	    r--;

	if (l == r)
	    break;

	swap(v, l, r);
    }	

    qsort(v, left, l);
    qsort(v, l + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}
