#include <iostream>
#include <fstream>
#include <string>


// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "sz.txt";
const std::string KEYS_FILE_NAME = "klucze2.txt";
const std::string OUTPUT_FILE_NAME = "wynik4b.txt";

// =====================================================================


// Decrypts word by reversing the Vigenere alphabetical shift
void DecryptWord (std::string& word, const std::string& key) {
    const size_t keySize = key.size();
    for (size_t i = 0; i < word.size(); i++) {
        int keyOffSet = key[i % keySize] - ('A' - 1);   // From 'A'
        word[i] -= keyOffSet;

        if (word[i] < 'A') { word[i] += 26; }
    }
}


int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "ERROR: File " << INPUT_FILE_NAME << " not found" << std::endl; return 1; }

    std::ifstream keysFile(KEYS_FILE_NAME);
    if (!keysFile) { std::cerr << "ERROR: File " << KEYS_FILE_NAME << " not found" << std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "ERROR: Could not create output file" << std::endl; return 1; }

    std::string word, key;

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print ("b:\nodszyfrowane słowa: ");

    while (inputFile >> word && keysFile >> key) {
        DecryptWord(word, key);
        Print(word);
    }

    return 0;
}