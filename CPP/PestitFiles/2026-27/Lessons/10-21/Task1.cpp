#include <iostream>
#include <fstream>

const std::string INPUT_FILE = "input.txt";


bool IsPalindrome (const std::string& str) {
    for (size_t i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::string tempWord;
    unsigned int ctr = 0;

    while (inputFile >> tempWord) {
        if (IsPalindrome(tempWord)) {
            ++ctr;
        }
    }

    std::cout << "Ilość: " << ctr;

    return 0;
}
