#include <iostream>


void printArray(const int* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}


// Time complexity: O(n^2) (nested loop)
void bubbleSort(int* arr, size_t size) {
    if (size < 2) { return; }
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {  // std::swap(arr[j], arr[j + 1]) <utility>
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    constexpr size_t arrSize = 6;
    int arr[arrSize] {3, 53, 1, 412, 3, 5};

    printArray(arr, arrSize);
    bubbleSort(arr, arrSize);
    printArray(arr, arrSize);

    return 0;
}



