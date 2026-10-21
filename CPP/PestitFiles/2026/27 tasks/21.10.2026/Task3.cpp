#include <iostream>
#include <fstream>
#include <unordered_map>

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
    unsigned int max = 0, maxSum;

    std::unordered_map<unsigned int, unsigned int> domMap = {};

    while (inputFile >> tempWord) {
        unsigned int sum = SumASCIICode(tempWord);
        domMap[sum]++;
    }

    for (auto& [key, value] : domMap) {
        std::cout << key << ": " << value << "\n";
    }

    return 0;
}
