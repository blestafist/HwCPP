#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

// ================================== CONFIGURATION ==================================

const std::string INPUT_FILE_NAME = "file.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";

// ===================================================================================


std::string decreaseOne(std::string str) {
    int i = str.size() - 1;

    while (i >= 0) {
        if (str[i] > 'A') { 
            str[i]--; break;
        }
        else {
            str[i] = 'F';
            i--;
        }
    }

    return str;
}


int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);

    std::string word, maxWord = "";
    std::unordered_map<std::string, int> frequency; // word : count

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    while (inputFile >> word) {
        frequency[word]++;

        if (word.size() > maxWord.size() || (word.size() == maxWord.size() && word > maxWord)) {
            maxWord = word;
        }
    }

    Print("Największa liczba w pliku: ", maxWord);
    Print("Ilość jej występowań: ", frequency[maxWord]);

    std::string maxDecreased = decreaseOne(maxWord);
    Print("Liczb w pliku, które są o 1 mniejsze od maksymalnej wartości: ", frequency[maxDecreased]);

    return 0;
}
