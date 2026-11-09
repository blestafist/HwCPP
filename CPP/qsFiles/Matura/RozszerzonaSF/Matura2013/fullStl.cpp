#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <functional>

// ============================= CONFIGURATION ========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wyniki6.txt";

// ====================================================================


// Previous digit less or equal next
bool IsDigitsGrowing (const std::string& word) {
    return std::adjacent_find(word.begin(), word.end(), std::greater<char>()) == word.end();
    // iterates through the string, if no invalid elements are found, returns an iterator
}


bool FirstDigitEqualLast (const int decimal) {
    std::string decStr = std::to_string(decimal);   // writes int to string
    return decStr.front() == decStr.back();
}


int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "ERROR: File" << INPUT_FILE_NAME << "not found" << std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "ERROR: Could not create output file" << std::endl; return 1; }

    std::string word,
    minGrowing = "",
    maxGrowing = "";

    int firstEqualLast = 0,
    decimalFirstEqualLast = 0,
    growingWords = 0;     // Previous digit less or equal next

    int minDecValue = std::numeric_limits<int>::max(),
    maxDecValue = -1;

    while (inputFile >> word) {
        if (word.front() == word.back()) { firstEqualLast++; }

        int decimalNum = std::stoi(word, nullptr, 8);
        if (FirstDigitEqualLast(decimalNum)) { decimalFirstEqualLast++; }

        if (IsDigitsGrowing(word)) {
            growingWords++;

            if (minDecValue > decimalNum) {
                minDecValue = decimalNum;
                minGrowing = word; 
            }

            if (maxDecValue < decimalNum) { 
                maxDecValue = decimalNum;
                maxGrowing = word; 
            }
        }
    }
    
    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("a:\nIlość liczb w których pierwsza cyfra równa ostatniej: ", firstEqualLast);
    Print("b:\nPierwsza cyfra równa ostatniej w systemie dziesiętnym: ", decimalFirstEqualLast);
    Print("c:\nIlość liczb spełniających warunek: ", growingWords, " najmniejsza liczba: ", minGrowing, " największa liczba: ", maxGrowing);

    return 0;
}
