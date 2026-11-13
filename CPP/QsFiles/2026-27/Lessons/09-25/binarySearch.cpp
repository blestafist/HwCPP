#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>


static constexpr size_t npos = -1;


// Time complexity: O(log n) (2^steps = n: halving search range each step)
size_t binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return static_cast<size_t>(mid);
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return npos;
}


int main() {
    srand(time(nullptr));

    constexpr size_t vecSize = 10;
    std::vector<int> arr(vecSize);
    for (int& x : arr) {
        x = rand() % 30;
    }

    std::sort(arr.begin(), arr.end());

    for (int x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    int target = 10;  // Enter target number here

    size_t idx = binarySearch(arr, target);

    if (idx != npos) std::cout << idx << '\n';
    else std::cout << "Not found\n";

    return 0;
}
