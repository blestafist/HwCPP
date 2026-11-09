#include <iostream>
#include <fstream>
#include <string>
#include <limits>


// ============================= CONFIGURATION ========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wyniki6.txt";

// ====================================================================


int OctToDecimal (const std::string& word) {
    int decimal = 0;

    for (char c : word) {
        decimal = decimal * 8 + (c - '0'); 
    }
    return decimal;
}


// Previous digit less or equal next
bool IsDigitsGrowing (const std::string& word) {
    for (size_t i = 0; i < word.size() - 1; i++) {
        if (word[i] > word[i + 1]) { return false; }
    }
    return true;
}


bool FirstDigitEqualLast (int decimal) {
    int lastDigit = decimal % 10;

    while (decimal >= 10) {
        decimal /= 10;
    }
    return decimal == lastDigit;    // Decimal becomes first digit after division
}


int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "ERROR: File" << INPUT_FILE_NAME << "not found" << std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);

    std::string word,
    minGrowing = "",
    maxGrowing = "";

    int firstEqualLast = 0,
    decimalFirstEqualLast = 0,
    growingWords = 0;     // Previous digit less or equal next

    int minDecValue = std::numeric_limits<int>::max(),
    maxDecValue = -1;

    while (inputFile >> word) {
        if (word[0] == word.back()) { firstEqualLast++; }

        int decimalNum = OctToDecimal(word);
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
