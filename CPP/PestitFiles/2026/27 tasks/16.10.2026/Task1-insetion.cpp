#include <iostream>
#include <vector>
#include <fstream>


const std::string INPUT_FILE = "liczby_do_zadania.txt";
const std::string OUTPUT_FILE = "zadanie1_sortowanie_insertion.txt";


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


int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::ofstream outputFile (OUTPUT_FILE);

    int temp;
    std::vector<int> arr;

    while (inputFile >> temp) {
        arr.push_back(temp);
    }

    InsertionSort (arr);

    for (auto i : arr) {
        std::cout << i << "\n";
        outputFile << i << "\n";
    }

    return 0;
}
