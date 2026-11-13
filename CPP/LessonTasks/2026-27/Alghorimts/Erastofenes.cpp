#include <cstddef>
#include <iostream>

template <size_t len>
void GenerateAll (bool (&arr)[len]) {
    arr[0] = false; arr[1] = false;

    for (size_t i = 2; i < len; ++i) {
        arr[i] = true;
    }
}

template <size_t len>
void Erastofenes (bool (&arr)[len]) {
    for (size_t i = 2; i * i < len; ++i) {
        if (!arr[i]) { continue; }

        for (size_t j = i * i; j < len; j += i) {
            arr[j] = false;
        }
    }
}

template<size_t len>
void PrintErastofenes (bool (&arr)[len]) {
    for (size_t i = 2; i < len; ++i) {
        if (arr[i]) { std::cout << i << '\n'; }
    }
}

int main () {
    bool arr[7001];
    GenerateAll(arr);
    Erastofenes(arr);
    PrintErastofenes(arr);

    return 0;
}
