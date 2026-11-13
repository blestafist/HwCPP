#include <iostream>
#include <fstream>
#include <string>


// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "tj.txt";
const std::string KEYS_FILE_NAME = "klucze1.txt";
const std::string OUTPUT_FILE_NAME = "wynik4a.txt";

// =====================================================================


// Encrypts a word using the Vigenere cipher with a cyclic key
void EncryptWord (std::string& word, const std::string& key) {
    const size_t keySize = key.size();
    for (size_t i = 0; i < word.size(); i++) {
        int keyOffSet = key[i % keySize] - ('A' - 1);   // From 'A'
        word[i] += keyOffSet;

        if (word[i] > 'Z') { word[i] -= 26; }
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

    Print ("a:\nzaszyfrowane słowa: ");

    while (inputFile >> word && keysFile >> key) {
        EncryptWord(word, key);
        Print(word);
    }

    return 0;
}