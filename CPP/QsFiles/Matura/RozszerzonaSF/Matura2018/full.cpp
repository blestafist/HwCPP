#include <iostream>
#include <fstream>
#include <vector>
#include <utility>


// ============================= CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string OUTPUT_FILE_NAME = "wyniki6.txt";

// =======================================================================


bool ContainsSubString (const std::string& sub, const std::string& text) {
    size_t subSize = sub.size();
    size_t textSize = text.size();

    if (textSize < subSize) { return false; }
    
    for (size_t i = 0; i <= textSize - subSize; i++) {
        size_t j = 0;
        while (j < subSize && sub[j] == text[i + j]) {
            j++;
        }
        if (j == subSize) { return true; }  // If the loop completed all symbols are equal
    }
    return false;
}


void SortString(std::string& s) {
    size_t n = s.size();
    if (n < 2) { return; }
    
    char temp;
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - 1 - i; j++) {
            if (s[j] > s[j + 1]) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}


bool IsAnagram (std::string word1, std::string word2) {
    if (word1.size() != word2.size()) { return false; }

    SortString(word1);
    SortString(word2);

    return word1 == word2;
}


int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "ERROR: File" << INPUT_FILE_NAME << " not found" << std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening ouputFile" << std::endl; return 1; }

    std::string word1, word2;

    int counterEndsA = 0, 
    countContains = 0,
    countAnagrams = 0;

    std::vector<std::pair<std::string, std::string>> anagramPairs;

    while (inputFile >> word1 >> word2) {
        if (word1[word1.size() - 1] == 'A') { counterEndsA++; }
        if (word2[word2.size() - 1] == 'A') { counterEndsA++; }

        if (ContainsSubString(word1, word2)) { countContains++; }

        if (IsAnagram(word1, word2)) { countAnagrams++; anagramPairs.emplace_back(word1, word2);}
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