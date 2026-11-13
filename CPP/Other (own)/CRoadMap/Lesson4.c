#include <stdio.h>
#include <stdlib.h>

struct Student{
    char grade; // 1 byte + 3 byes padding to align to 4-block
    int age; // 4 bytes
    float score; // 4 bytes
};

int main() {
    struct Student student; // creating a struct
    student.age = 1488; // filling it
    student.grade = '6';
    student.score = 19.39f;

    printf("%zu\n", sizeof(student)); // 12 because the processor aligns to 4-blocks

    return 0;
}
