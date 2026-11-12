#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <ctime>
#include <algorithm>

static constexpr size_t npos = -1;

size_t BinarySearch (int (&arr)[20], int target) {
    size_t mid, left = 0, right = 20 - 1;

    while (left < right) {
        mid = left + ((right - left) / 2);

        if (arr[mid] == target) { return mid; }
        else if (arr[mid] > target) { left = mid - 1; continue; }
        else { right = mid + 1; continue; }
    }

    return npos;
}

int main () {
    int arr[20] = {};
    srand(time(NULL));

    for (auto& i : arr) {
        i = rand() % 10;
    }

    std::sort(arr, arr + 20);

    for (const auto& i : arr) {
        std::cout << i << ' ';
    }

    std::cout << "\n" << BinarySearch(arr, 0);
}
