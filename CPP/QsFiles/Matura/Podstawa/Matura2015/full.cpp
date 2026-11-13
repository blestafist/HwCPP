#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>


// ======================== CONFIGURATION ========================

constexpr const char* INPUT_FILE = "slowa.txt";
constexpr const char* INPUT_FILE_NEW = "nowe.txt";
constexpr const char* OUTPUT_FILE = "wynik5.txt";

constexpr int INTERVAL_N = 12;

// ===============================================================


int main() {
    std::ifstream inputFile(INPUT_FILE), inputFileNew(INPUT_FILE_NEW);
    std::ofstream outputFile(OUTPUT_FILE);

    if (!inputFile || !inputFileNew || !outputFile) { std::cerr << "ERROR: File access error!" << std::endl; return 1; }

    int n [INTERVAL_N] {};

    std::vector<std::string> seq;
    std::unordered_map<std::string, int> occurrences, mirrorOcc;

    auto rev = [](const std::string& s) {
        std::string temp = s;
        std::reverse(temp.begin(), temp.end());
        return temp;
    };

    std::string word;
    while (inputFileNew >> word) {
        seq.push_back(word);
        occurrences.emplace(word, 0);

        std::string mirrorWord = rev(word);
        mirrorOcc.emplace(mirrorWord, 0);
    }

    while (inputFile >> word) {
        size_t size = word.size();
        ++n[size - 1];

        if (occurrences.count(word)) { ++occurrences[word]; }
        if (mirrorOcc.count(word)) { ++mirrorOcc[word]; }
    }

    auto Print = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("5.1: ");

    for (size_t i = 0; i < INTERVAL_N; ++i) {
        Print(i + 1, ' ', n[i]);
    }

    Print("\n5.2: ");

    for (auto& word : seq) {
        Print(word, ' ', occurrences[word], ' ', mirrorOcc[rev(word)]);
    }

    return 0;
}
