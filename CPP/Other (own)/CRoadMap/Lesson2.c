#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arrHeap = malloc(sizeof(int) * 5); // выделение памяти в куче под 5 элементов

    for (int i = 1; i <= 5; ++i) {
        *(arrHeap + i - 1) = i; // заполняем от 1 до 5
    }

    for (int i = 0; i < 5; ++i) { // выводим, теперь удобнее будет сделать от 0
        printf("%d\n", *(arrHeap + i)); // выводим со \n
    }

    free(arrHeap); // освобождаем память
    arrHeap = NULL; // присваивание NULL чтобы избежать висячего указателя (и Segmentation Fault соотвественно)

    return 0;
}