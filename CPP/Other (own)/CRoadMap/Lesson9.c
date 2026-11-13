#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10;
    int* ptr = &x;

    printf("%p\n", ptr);
    printf("%d\n", *ptr);

    int** ptr2 = &ptr;
    printf("%p\n", ptr2);
    printf("%p\n", *ptr2);
    printf("%d\n", **ptr2);

    **ptr2= 12;
    printf("%d\n", x);

    return 0;
}