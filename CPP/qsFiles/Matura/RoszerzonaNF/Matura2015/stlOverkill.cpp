#include <algorithm>    // std::count, std::remove_if
#include <cstddef>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>


// ============================= CONFIGURAION =============================

const std::string INPUT_FILE = "liczby.txt";
const std::string OUTPUT_FILE = "wynik4.txt";

using Pair = std::pair<std::string, size_t>;

// ========================================================================


bool AreZerosMajority (const std::string& binaryStr) {
    size_t zerosCounter = std::count(binaryStr.begin(), binaryStr.end(), '0');
    return zerosCounter > (binaryStr.size() / 2);
}


bool DivisibleBy8 (const std::string& str) {
    size_t n = str.size();
    if (n < 3) {
        return (str == "0" || str == "00");
    }
    return (str[n - 3] == '0') && (str[n - 2] == '0') && (str[n - 1] == '0');
}


// Strings have the same length, so lexicographical comparison == numeric comparison
void ExtractShortestBinary (std::vector<Pair>& binary) {
    if(binary.empty()) { return; }

    std::string minBinary = binary[0].first;
    for (size_t i = 1; i < binary.size(); ++i) {
        if (binary[i].first < minBinary) { minBinary = binary[i].first; }
    }
    
    binary.erase(
        std::remove_if(binary.begin(), binary.end(), 
            [&](const auto& p) {
                return p.first > minBinary;
            }),
        binary.end()
    );
}


// Strings have the same length, so lexicographical comparison == numeric comparison
void ExtractLongestBinary (std::vector<Pair>& binary) {
    if(binary.empty()) { return; }

    std::string maxBinary = binary[0].first;
    for (size_t i = 1; i < binary.size(); ++i) {
        if (binary[i].first > maxBinary) { maxBinary = binary[i].first; }
    }
    binary.erase(
        std::remove_if(binary.begin(), binary.end(),
            [&](const auto& p) {
            return p.first < maxBinary;
        }),
        binary.end() 
    );
}


int main() {
    std::ifstream inputFile (INPUT_FILE);
    if(!inputFile) { std::cerr << "ERROR: File " << INPUT_FILE << " not found" <<std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE);
    if(!outputFile) { std::cerr << "Could not create outputFile" << std::endl; return 1; }

    int zerosMoreCounter = 0,
    divisibleBy2 = 0, divisibleBy8 = 0;

    std::vector<Pair> shortestBinary;
    size_t minBinarySize = std::numeric_limits<size_t>::max();

    std::vector<Pair> longestBinary;
    size_t maxBinarySize = 0;

    int rowNum = 1;
    std::string binaryStr;
    while (inputFile >> binaryStr) {
        if (AreZerosMajority(binaryStr)) { ++zerosMoreCounter; }

        if (!binaryStr.empty() && binaryStr.back() == '0') { 
            ++divisibleBy2; 
            if(DivisibleBy8(binaryStr)) { ++divisibleBy8; }
        }

        size_t currSize = binaryStr.size();
        if (currSize < minBinarySize) { 
            minBinarySize = currSize; shortestBinary.clear(); 

            shortestBinary.emplace_back(binaryStr, rowNum); 
        }
        else if (currSize == minBinarySize) {
            shortestBinary.emplace_back(binaryStr, rowNum);
        }

        if (currSize > maxBinarySize) {
            maxBinarySize = currSize; longestBinary.clear();

            longestBinary.emplace_back(binaryStr, rowNum);
        }   
        else if (currSize == maxBinarySize) {
            longestBinary.emplace_back(binaryStr, rowNum);
        }
        
        ++rowNum;
    }
    ExtractShortestBinary(shortestBinary);
    ExtractLongestBinary(longestBinary);

    auto Print = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("1.\n", zerosMoreCounter);
    Print("2.\n", "podzielnych przez 2: ", divisibleBy2, " podzielnych przez 8: ", divisibleBy8);
    Print("3.");

    if (!shortestBinary.empty()) {
        const auto& elem = shortestBinary[0];
        size_t row = elem.second;
        Print("najmniejsza: ", row);
    }

    if (!longestBinary.empty()) {
        const auto& elem = longestBinary[0];
        size_t row = elem.second;
        Print("największa: ", row);
    }

    return 0;
}