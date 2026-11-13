#include "cstddef"
#include <iostream>
#include <utility>

template<typename T, size_t len>
void SelectionSort (T (&arr)[len]) {
    for (size_t i = 0; i < len - 1; ++i) {
        size_t minValueIndex = i;
        for (size_t fastPtr = i + 1; fastPtr < len; ++fastPtr) {
            if (arr[minValueIndex] > arr[fastPtr]) {
                minValueIndex = fastPtr;
            }
        }

        std::swap(arr[minValueIndex], arr[i]);
    }
}

template<typename T, size_t len>
void InsertionSort (T (&arr)[len]) {
    for (size_t i = 1; i < len; ++i) {
        T savedValue = arr[i];
        size_t fastPtr = i;

        while (fastPtr > 0 && arr[fastPtr - 1] > savedValue) {
            arr[fastPtr] = arr[fastPtr - 1];
            --fastPtr;
        }

        arr[fastPtr] = savedValue;
    }
}

void Recurr (int (&arr)[], int size, int curr) {
    if (curr == size) {
        return;
    }

    std::cout << arr[curr] << "\n";

    Recurr(arr, size, curr + 1);
}

int Factorial (int num) {
    if (num <= 0) {
        return 0;
    }

    return num + Factorial(num - 1);
}

void FibonnaciPrint (int firstNum, int secondNum) {
    if (secondNum >= 100) {
        return;
    }

    std::cout << firstNum << '\n';
    int sum = firstNum + secondNum;
    FibonnaciPrint(secondNum, sum);
}

void Silnia (int num, int& wynik) {
    if (num > 0) {
        wynik *= num;
        Silnia(num - 1, wynik);
    }

    else { return; }
}


int main () {
    int wynik = 1;
    Silnia(5, wynik);

    std::cout << wynik << std::endl;
    return 0;
}
