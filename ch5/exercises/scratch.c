#include <stdio.h>
#include <ctype.h>

void modifyArray(char[]);

int main(void)
{
    // Test pass by referance with arrays
    char a[14] = "Hello, World!";

    printf("Original:\t%s\n", a);
    modifyArray(a);
    printf("Modified:\t%s\n", a);
    return 0;
}

void modifyArray(char arr[])
{
    arr[0] = 'Y';
    printf("Inside Function:\t%s\n", arr);
}
