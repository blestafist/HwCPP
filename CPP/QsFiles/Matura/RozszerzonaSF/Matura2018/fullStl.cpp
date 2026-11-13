#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>


// ============================= CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string OUTPUT_FILE_NAME = "wyniki6.txt";

const int ALPHABET_SIZE = 26;

// =======================================================================


bool ContainsSubString (const std::string& sub, const std::string& text) {
    return text.find(sub) != std::string::npos;
}


bool IsAnagramFast (const std::string& word1, const std::string& word2) {
    if (word1.size() != word2.size()) { return false; }

    int charCounts[ALPHABET_SIZE] {};    

    for (size_t i = 0; i < word1.size(); i++) {
        charCounts[word1[i] - 'A']++;
        charCounts[word2[i] - 'A']--;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (charCounts[i] != 0) { return false; }   // Nothing changes - letters count is equal
    }
    return true;
}


int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "ERROR: File " << INPUT_FILE_NAME << " not found" << std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening ouputFile" << std::endl; return 1; }

    std::string word1, word2;

    int counterEndsA = 0, 
    countContains = 0,
    countAnagrams = 0;

    std::vector<std::pair<std::string, std::string>> anagramPairs;

    while (inputFile >> word1 >> word2) {
        if (!word1.empty() && word1.back() == 'A') { counterEndsA++; }
        if (!word1.empty() && word2.back() == 'A') { counterEndsA++; }

        if (ContainsSubString(word1, word2)) { countContains++; }

        if (IsAnagramFast(word1, word2)) { countAnagrams++; anagramPairs.emplace_back(word1, word2);}
    }

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("6.1\n", "Liczba słow kończących się na 'A': ", counterEndsA);
    Print("6.2\n", "Liczba wierszy: ", countContains);
    Print("6.3\n", "Liczba par: ", countAnagrams);

    Print("Pary:");

    for (const auto& [a, b] : anagramPairs) {
        Print(a, " ", b);
    }

    return 0;
}