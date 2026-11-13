#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>


// ============================ CONFIGURATION ========================

const std::string INPUT_FILE_NAME = "NAPIS.TXT";
const std::string OUTUPUT_FILE_NAME = "ZADANIE5.TXT";

// ===================================================================


bool IsPrime (int num) {
    if (num < 2) { return false; }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) { return false; }
    }
    return true;
}


bool IsASCII_SumPrime (const std::string& word) {
    int sum = 0;
    for (char c : word) {
        sum += c;
    }
    return IsPrime(sum);
}


bool IsASCII_Growing (const std::string& word) {
    for (size_t i = 0; i < word.size() - 1; i++) {
        if (word[i] >= word[i + 1]) { return false; }
    }
    return true;
}


int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "ERROR File: " << INPUT_FILE_NAME << " not found" << std::endl; return 1;}

    std::ofstream outputFile(OUTUPUT_FILE_NAME);

    std::string word;

    int counterPrime = 0;

    std::vector<std::string> growingWords,  repeatedWords;
    std::unordered_map<std::string, int> words;

    while(inputFile >> word) {
        if (IsASCII_SumPrime(word)) { counterPrime++; }

        if (IsASCII_Growing(word)) { growingWords.push_back(word); }

        int& count = words[word];
        if (count == 1) {
            repeatedWords.push_back(word);
        }
        count++;
    }

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("a:\nLiczba napisów pierszych: ", counterPrime);
    Print("b:\nNapisy rosnące:");

    for (const std::string& s : growingWords) {
        Print(s);
    }

    Print("c:\nsłowa występujące więcej niż raz: ");

    for (const std::string& s : repeatedWords) {
        Print(s);
    }
    return 0;
}