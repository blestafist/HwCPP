#include <stdio.h>
#include <stdlib.h>

union Data {
    int i;
    float f;
    char str[4];
};

int main() {
    union Data data;
    data.f = 2.0f;
    data.i = 12;

    printf("%d\n", data.i);
    printf("%f\n", data.f);

    data.f = 12.222f;
    printf("%d\n", data.i);
    printf("%f\n", data.f);

    return 0;
}