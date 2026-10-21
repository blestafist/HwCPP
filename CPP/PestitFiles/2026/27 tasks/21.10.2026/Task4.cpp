#include <climits>
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>

const std::string INPUT_FILE = "input.txt";


unsigned int SumASCIICode (const std::string& str) {
    unsigned int sum = 0;

    for (char c : str) {
        sum += static_cast<unsigned int>(c);
    }

    return sum;
}


int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::string tempWord;
    unsigned int max = 0, min = UINT_MAX;

    std::vector<unsigned int> arr = {};

    while (inputFile >> tempWord) {
        unsigned int sum = SumASCIICode(tempWord);
        arr.push_back(sum);
    }

    for (auto i : arr) {
        if (min > i) {
            min = i;
        } if (max < i) {
            max = i;
        }
    }

    std::cout << "max: " << max << "\n";
    std::cout << "min: " << min << "\n";

    std::cout << "nwd: " << std::gcd(max, min);

    return 0;
}
