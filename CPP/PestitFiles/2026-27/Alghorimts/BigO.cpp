#include <iostream>
#include <utility>

void BubbleSort (int (&arr)[5]) {
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 4 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main () {
    int arr[5] = { 12, 5, 17, 21, 9 };

    for (auto i : arr) {
        std::cout << i << "\n";
    }

    BubbleSort(arr);

    for (auto i : arr) {
        std::cout << i << "\n";
    }

    return 0;
}
