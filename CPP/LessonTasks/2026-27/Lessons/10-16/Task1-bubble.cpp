#include <iostream>
#include <vector>
#include <fstream>
#include <utility>


const std::string INPUT_FILE = "liczby_do_zadania.txt";
const std::string OUTPUT_FILE = "zadanie1_sortowanie_bubble.txt";


void BubbleSort (std::vector<int>& arr) {
    if (arr.size() < 2) return;
    
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) { break; }
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

    BubbleSort (arr);

    for (auto i : arr) {
        std::cout << i << "\n";
        outputFile << i << "\n";
    }

    return 0;
}
