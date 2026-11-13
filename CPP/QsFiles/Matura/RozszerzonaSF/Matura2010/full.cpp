#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <array>
#include <vector>
#include <algorithm>


// =========================== CONFIGURATION ==========================

const std::string INPUT_FILE = "anagram.txt";
const std::string OUTPUT_FILE_A = "odp_4a.txt";
const std::string OUTPUT_FILE_B = "odp_4b.txt";

const size_t WORDS_PER_LINE = 5;

// ====================================================================


bool SameLength (const std::array<std::string, WORDS_PER_LINE>& line) {
    const size_t targetLen = line[0].size();
    for (size_t i = 1; i < WORDS_PER_LINE; i++) {
        if (line[i].size() != targetLen) { return false; }
    }
    return true;
}


// Sorting word copies and comparing them to the first word
bool AllAnagrams (std::array<std::string, WORDS_PER_LINE> line) {
    std::sort(line[0].begin(), line[0].end());
    for (size_t i = 1; i < WORDS_PER_LINE; i++) {
        std::sort(line[i].begin(), line[i].end());
        if (line[0] != line[i]) { return false; }
    }
    return true;
}


// Merges vector of words into a single space-separated string
std::string MergeLine (const std::array<std::string, WORDS_PER_LINE>& line) {
    std::string result = "";
    for (size_t i = 0; i < WORDS_PER_LINE; i++) {
        result += line[i];
        if (i < WORDS_PER_LINE - 1) { result += " "; }
    }
    return result;
}


int main() {
    std::ifstream inputFile(INPUT_FILE);
    if (!inputFile) { std::cerr << "ERROR: File " << INPUT_FILE << " not found" << std::endl; return 1; }

    std::ofstream outputFileA(OUTPUT_FILE_A), outputFileB(OUTPUT_FILE_B);
    if (!outputFileA || !outputFileB) { std::cerr << "ERROR: Could not create output file" << std::endl; return 1; }

    std::string word;
    std::array<std::string, WORDS_PER_LINE> line;
    std::vector <std::string> sameLenResults, anagramResults;

    size_t i = 0;   // Index of word in line
    while (inputFile >> word) {
        line[i++] = word;

        if (i == WORDS_PER_LINE) {
            if (SameLength(line)) {
                std::string merged = MergeLine(line);    
                sameLenResults.push_back(merged);
                if (AllAnagrams(line)) { anagramResults.push_back(merged); } 
            }
            i = 0;
        }
    }
    
    auto PrintA = [&] (auto&&... args) { (std::cout << ... << args) << '\n'; (outputFileA << ... << args) << '\n'; };
    auto PrintB = [&] (auto&&... args) { (std::cout << ... << args) << '\n'; (outputFileB << ... << args) << '\n'; };

    PrintA("a:\n");
    for (const std::string& s : sameLenResults) { PrintA(s); }

    PrintB("\nb:\n");
    for (const std::string& s : anagramResults) { PrintB(s); }

    return 0;
}