#include <iostream>
#include <fstream>
#include <unordered_map>

const std::string INPUT_FILE = "input.txt";


int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::string tempWord;
    unsigned int ctr = 0;

    std::string maxWord;
    int max = 0;

    std::unordered_map<std::string, int> arr = {};

    while (inputFile >> tempWord) {
        arr[tempWord]++;
    }

    for (auto& [key, value] : arr) {
        if (value > max) {
            max = value;
            maxWord = key;
        }
    }

    std::cout << maxWord << ' ' << max;

    return 0;
}
