#include <algorithm>    // std::count, find_first_not_of()
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>


// ============================= CONFIGURAION =============================

const std::string INPUT_FILE = "liczby.txt";
const std::string OUTPUT_FILE = "wynik4.txt";

using BinaryPair = std::pair<std::string, size_t>;

// ========================================================================


bool AreZerosMajority (const std::string& binaryStr) {
    size_t zerosCounter = std::count(binaryStr.begin(), binaryStr.end(), '0');
    return zerosCounter > (binaryStr.size() / 2);
}


bool IsDivisibleBy8 (const std::string& str) {
    size_t n = str.size();
    if (n < 3) {
        return str.find_first_not_of('0') == std::string::npos;
    }
    return (str[n - 3] == '0') && (str[n - 2] == '0') && (str[n - 1] == '0');
}


bool IsBinarySmaller (const std::string& s1, const std::string& s2) {
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    return s1 < s2;
}


int main() {
    std::ifstream inputFile (INPUT_FILE);
    if(!inputFile) { std::cerr << "ERROR: File " << INPUT_FILE << " not found" <<std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE);
    if(!outputFile) { std::cerr << "Could not create outputFile" << std::endl; return 1; }

    int zeroMajorityCount = 0;
    int divisibleBy2 = 0, divisibleBy8 = 0;
    
    BinaryPair shortestBinary;
    BinaryPair longestBinary;

    size_t rowNum = 1;
    std::string currentBinary;
    while (inputFile >> currentBinary) {
        if (AreZerosMajority(currentBinary)) { ++zeroMajorityCount; }

        if (!currentBinary.empty() && currentBinary.back() == '0') {
            ++divisibleBy2; 
            if(IsDivisibleBy8(currentBinary)) { ++divisibleBy8; }
        }

        if (rowNum == 1 || IsBinarySmaller(currentBinary, shortestBinary.first)) {
            shortestBinary = {currentBinary, rowNum };
        }

        if (rowNum == 1 || IsBinarySmaller(longestBinary.first, currentBinary)) {
            longestBinary = { currentBinary, rowNum };
        }
        
        ++rowNum;
    }

    auto Print = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("4.1: ", zeroMajorityCount);
    Print("4.2: ", "podzielnych przez 2: ", divisibleBy2, " podzielnych przez 8: ", divisibleBy8);
    Print("4.3: ");
    Print("najmniejsza: ", shortestBinary.second);
    Print("największa: ", longestBinary.second);

    return 0;
}