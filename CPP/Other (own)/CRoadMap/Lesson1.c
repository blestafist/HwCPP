#include <stdio.h>

int main() {
    // Task 1.2
    int x = 12; // creating var on stack
    int* ptrX = &x; // a ptr looking at X

    *ptrX = 15; // changing via ptr

    printf("1.1\n%p", ptrX); // printing adress
    printf("\n\n1.2");

    int arr[3] = {10, 20, 30}; // creating array (legacy)
    int* ptrArr = arr; // init with arr bcs arr is pointer to a first element in C

    printf("%d\n", *ptrArr); // printing first element of array
    ptrArr++; // increasing ptr 
    printf("%d\n", *ptrArr); // printing next element of array (арифметика указателей)

    return 0;
}