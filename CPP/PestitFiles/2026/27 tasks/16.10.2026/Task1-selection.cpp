#include <iostream>
#include <vector>
#include <fstream>
#include <utility>


const std::string INPUT_FILE = "liczby_do_zadania.txt";
const std::string OUTPUT_FILE = "zadanie1_sortowanie_selection.txt";


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



int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::ofstream outputFile (OUTPUT_FILE);

    int temp;
    std::vector<int> arr;

    while (inputFile >> temp) {
        arr.push_back(temp);
    }

    SelectionSort (arr);

    for (auto i : arr) {
        std::cout << i << "\n";
        outputFile << i << "\n";
    }

    return 0;
}
