#include <iostream>
#include <vector>
#include <fstream>
#include <utility>


const std::string INPUT_FILE = "liczby_do_zadania.txt";


void InsertionSort (std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        size_t ptr = i;
        int val = arr[i];

        while (ptr > 0 && arr[ptr - 1] > val) {
            arr[ptr] = arr[ptr - 1];
            --ptr;
        }

        arr[ptr] = val;
    }
}


void SelectionSort (std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        size_t minIdx = i;
        for (size_t ptr = i; ptr < arr.size(); ++ptr) {
            if (arr[minIdx] > arr[ptr]) {
                minIdx = ptr;
            }
        }

        if (minIdx != i) {
            std::swap(arr[i], arr[minIdx]);
        }
    }
}


void BubbleSort (std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    int temp;
    std::vector<int> arr;

    while (inputFile >> temp) {
        arr.push_back(temp);
    }

    InsertionSort(arr);

    for (auto i : arr) {
        std::cout << i << "\n";
    }

    return 0;
}
