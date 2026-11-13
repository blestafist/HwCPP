#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


// =========================== CONFIGURATION ===========================

const std::string IN_A = "tj.txt",  KEY_A = "klucze1.txt", OUT_A = "wynik4a.txt";
const std::string IN_B = "sz.txt",  KEY_B = "klucze2.txt", OUT_B = "wynik4b.txt";

// =====================================================================


// Encrypts a word using the Vigenere cipher with a cyclic key
void EncryptWord (std::string& word, const std::string& key) {
    size_t kIdx = 0;
    const size_t keySize = key.size();

    std::transform(word.begin(), word.end(), word.begin(), [&](char c) {
        int offset = key[kIdx++ % keySize] - ('A' - 1);
        
        int encrypted = c + offset;
        if (encrypted > 'Z') { encrypted -= 26; }

        return static_cast<char>(encrypted);
    });
}


// Decrypts word by reversing the Vigenere alphabetical shift
void DecryptWord (std::string& word, const std::string& key) {
    size_t kIdx = 0;
    const size_t keySize = key.size();

    std::transform(word.begin(), word.end(), word.begin(), [&](char c) {
        int offset = key[kIdx++ % keySize] - ('A' - 1);

        int decrypted = c - offset;
        if (decrypted < 'A') { decrypted += 26; }

        return static_cast<char>(decrypted);
    });
}


int main() {
    std::ifstream fInA(IN_A), fInB(IN_B);
    if (!fInA || !fInB) { std::cerr << "ERROR: data file not found" << std::endl; return 1; }

    std::ifstream fKeyA(KEY_A), fKeyB(KEY_B);
    if (!fKeyA || !fKeyB) { std::cerr << "ERROR: keys file not found" << std::endl; return 1; }

    std::ofstream fOutA(OUT_A), fOutB(OUT_B);
    if (!fOutA || !fOutB) { std::cerr << "ERROR: Could not create output file" << std::endl; return 1; }

    std::string word, key;

    auto PrintA = [&] (auto&& arg) { (std::cout << arg) << '\n'; (fOutA << arg) << '\n'; };
    auto PrintB = [&] (auto&& arg) { (std::cout << arg) << '\n'; (fOutB << arg) << '\n'; };

    PrintA ("a:\nzaszyfrowane słowa: ");

    while (fInA >> word && fKeyA >> key) {
        EncryptWord(word, key);
        PrintA(word);
    }

    PrintB ("b:\nodszyfrowane słowa: ");

    while (fInB >> word && fKeyB >> key) {
        DecryptWord(word, key);
        PrintB(word);
    }

    return 0;
}