#include <algorithm>    // std::sort, std::all_of
#include <array>
#include <cstddef>
#include <fstream>
#include <numeric>    // std::accumulate
#include <iostream>
#include <sstream>    // std::istringstream
#include <string>
#include <vector>


// =========================== CONFIGURATION ==========================

const std::string INPUT_FILE = "anagram.txt";
const std::string OUTPUT_FILE_A = "odp_4a.txt";
const std::string OUTPUT_FILE_B = "odp_4b.txt";

const size_t WORDS_PER_LINE = 5;

// ====================================================================


bool SameLength (const std::array<std::string, WORDS_PER_LINE>& line) {
    return std::all_of(line.begin() + 1, line.end(), [&](const std::string& s) {
        return s.size() == line[0].size();
    });
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


int main() {
    std::ifstream inputFile(INPUT_FILE);
    if (!inputFile) { std::cerr << "ERROR: File " << INPUT_FILE << " not found" << std::endl; return 1; }

    std::ofstream outputFileA(OUTPUT_FILE_A), outputFileB(OUTPUT_FILE_B);
    if (!outputFileA || !outputFileB) { std::cerr << "ERROR: Could not create output file" << std::endl; return 1; }

    std::string word;
    std::array<std::string, WORDS_PER_LINE> line;
    std::vector <std::string> sameLenResults, anagramResults;

    std::string rawLine;
    while (std::getline(inputFile, rawLine)) {
        if (rawLine.empty()) { continue; }

        std::istringstream lineReader(rawLine);
        size_t count = 0;

        while (count < WORDS_PER_LINE && lineReader >> line[count]) {
            count++;
        }
        if (count == WORDS_PER_LINE) {
            if (SameLength(line)) {
            std::string merged = std::accumulate(line.begin() + 1, line.end(), line[0],
            [](const std::string& a, const std::string& b){
                return a + " " + b;
            });

            sameLenResults.push_back(merged);
            if (AllAnagrams(line)) { anagramResults.push_back(merged); }
            }
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