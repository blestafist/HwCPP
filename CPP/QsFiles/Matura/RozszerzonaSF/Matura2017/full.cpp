#include <iostream>
#include <fstream>
#include <string>
#include <limits>


// ============================= CONFIGURATION ==========================

const std::string INPUT_FILE_NAME = "binarne.txt";
const std::string OUTPUT_FILE_NAME = "zadanie4.txt";

// ======================================================================


bool IsBicyclic (const std::string& word) {
    size_t n = word.size();
    if (n % 2 != 0) { return false; }

    for (size_t i = 0; i < n / 2; i++) {
        if (word[i] != word[n / 2 + i]) { return false; }   // Checking the equality of the first half of a word with the second
    }
    return true;
}


int BinaryToDecimal (const std::string& binary) {
    long long decimal = 0;

    for (char c : binary) {
        decimal = decimal * 2 + (c - '0');
        if (decimal > 65535) { return decimal; }
    }
    return decimal;
}


bool IsInvalidBCD (const std::string& word) {
    size_t n = word.size();

    for (size_t i = 0; i < n / 4; i++) {
        int partSum = 0;
        for (size_t j = i * 4; j < i * 4 + 4; j++) {   // Splits a word into 4-character parts
            partSum = partSum * 2 + (word[j] - '0');
        }
        if (partSum > 9) { return true; }
    }
    return false;
}


int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "ERROR: File " << INPUT_FILE_NAME <<" not found" << std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile" << std::endl; return 1; }

    std::string word, biggestBinaryNum;

    size_t bicyclicCounter = 0,    
    maxBicyclicLength = 0, 
    incorrectCounter = 0,
    minIncorrectLength = std::numeric_limits<size_t>::max(),
    biggestDecimalNum = 0;
    
    std::string longestBicyclic = "";

    while (inputFile >> word) {
        size_t wordSize = word.size();

        if (IsBicyclic(word)) {
            bicyclicCounter++; 
            if (maxBicyclicLength < wordSize) { maxBicyclicLength = wordSize; longestBicyclic = word; }
        }
        
        if (IsInvalidBCD(word)) {
            incorrectCounter++;
            if (minIncorrectLength > wordSize) { minIncorrectLength = wordSize; } 
        }

        long long decimal = BinaryToDecimal(word);

        if (decimal <= 65535 && biggestDecimalNum < (size_t)decimal) {
        biggestDecimalNum = (size_t)decimal;
        biggestBinaryNum = word;
        }
    }

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("4.1\nLiczba napisów dwucyklicznych: ", bicyclicCounter, "\nnajdłuższy napis dwucykliczny: ", longestBicyclic, "\njego długość: ", maxBicyclicLength);
    Print("4.2\nLiczba niepoprawnych napisów: ", incorrectCounter, "\nnajmniejsza długość niepoprawnego napisu: ", minIncorrectLength);
    Print("4.3\nNajwiększa liczba w zapisie binarnym: ", biggestBinaryNum, ", jej zapis dziesiętny: ", biggestDecimalNum);

    return 0;
}