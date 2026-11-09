#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


// ========================== CONFIGURATION ==========================

const std::string INPUT_FILE = "dane.txt";
const std::string OUTPUT_FILE = "wyniki6.txt";

// ===================================================================


bool IsNumCorrect(const std::string& str) {
    long long condition = 0;
    int multipliers[11] { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1 };

    for (size_t i = 0; i < str.size(); ++i) {
        condition += (str[i] - '0') * multipliers[i];
    }
    return condition % 10 == 0;
}


int main() {
    std::ifstream inputFile(INPUT_FILE);
    if (!inputFile) { std::cerr << "ERROR: File " << INPUT_FILE << " not found" << std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE);
    if (!outputFile) { std::cerr << "Could not create outputFile" << std::endl; return 1; }

    int womenCounter = 0, mansCounter = 0;
    int bornInNovember = 0;

    std::vector <std::string> incorrect;

    std::string tempWord;
    while (inputFile >> tempWord) {
        if (tempWord.size() > 11) continue;
 
        int penultDigit = tempWord[9] - '0';
        if (penultDigit % 2 == 0) ++womenCounter;
        else ++mansCounter;

        int thirdAndFourthDigits = (tempWord[2] - '0') * 10 + (tempWord[3] - '0');

        if (thirdAndFourthDigits > 12) thirdAndFourthDigits -= 20;
        if (thirdAndFourthDigits == 11) ++bornInNovember;

        if (!IsNumCorrect(tempWord)) { incorrect.push_back(tempWord); }
    }
    
    auto Print = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("6.1: kobiet: ", womenCounter, " mężczyzn: ", mansCounter);
    Print("6.2: ", bornInNovember);
    Print("6.3: ");

    for (const auto& num : incorrect) {
        Print(num);
    }
    
    return 0;
}