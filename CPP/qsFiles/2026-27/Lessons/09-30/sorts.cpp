#include <algorithm>
#include <iostream>
#include <vector>


void printArr(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}


// Time complexity: O(n^2) (nested loop)
void selectionSort(std::vector<int>& arr) {
    if (arr.size() < 2) { return; }

    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIdx = i;

        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIdx]) { minIdx = j; }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}


// Time complexity: O(n) - best (already sorted), O(n^2) - avg/worst (nested loop)
void insertionSort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = static_cast<int>(i - 1);

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}


int main() {
    const std::vector<int> original { 1, 3, 64, 25, 12, 22, 11, 6, 0, 3 };

    std::vector<int> forSelection = original;
    std::vector<int> forInsertion = original;

    selectionSort(forSelection);
    printArr(forSelection);

    insertionSort(forInsertion);
    printArr(forInsertion);

    return 0;
}
