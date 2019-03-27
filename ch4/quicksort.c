#include <stdio.h>

void qsort(int[], int, int);
void swap(int[], int, int);

int main(void)
{
    int test1[10] = {9, 1, 3, 4, 2, 5, 8, 7, 0, 6};

    qsort(test1, 0, 9);
    
    for(int i = 0; i < 10; i++)
	printf(" %d ", test1[i]);

    return 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)		/* do nothing if array contains */
	return;			/* fewer than 2 elements */
    swap(v, left, (left + right) / 2); /* move partition elem */
    last = left;
    for (i = left + 1; i <= right; i++) /* partition */
	if (v[i] < v[left])
	    swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
