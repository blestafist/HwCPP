#include <fstream>
#include <functional>   // std::plus<>()
#include <iostream>
#include <numeric>  // std::inner_product
#include <string>
#include <vector>


// ========================== CONFIGURATION ==========================

const std::string INPUT_FILE = "dane.txt";
const std::string OUTPUT_FILE = "wyniki6.txt";

// ===================================================================


bool IsNumCorrect(const std::string& str) {
    if (str.size() != 11) return false;
    static const int multipliers[11] { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1 };

    long long condition = std::inner_product(str.begin(), str.end(), multipliers, 0LL, std::plus<>(), 
        [](char c, int m) { return (c - '0') * m; } );

    return condition % 10 == 0;
}


int main() {
    std::ifstream inputFile(INPUT_FILE);
    if (!inputFile) { std::cerr << "ERROR: File " << INPUT_FILE << " not found" << std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE);
    if (!outputFile) { std::cerr << "Could not create outputFile" << std::endl; return 1; }

    int womenCounter = 0, menCounter = 0;
    int bornInNovember = 0;

    std::vector <std::string> incorrect;

    std::string pesel;
    while (inputFile >> pesel) {
        if (pesel.size() < 11) continue;
 
        int penultDigit = pesel[9] - '0';
        if (penultDigit % 2 == 0) ++womenCounter;
        else ++menCounter;

        int month = std::stoi(pesel.substr(2, 2));
        if (month > 12) month -= 20;
        if (month == 11) ++bornInNovember;

        if (!IsNumCorrect(pesel)) { incorrect.push_back(pesel); }
    }
    
    auto Print = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("6.1: kobiet: ", womenCounter, " mężczyzn: ", menCounter);
    Print("6.2: ", bornInNovember);
    Print("6.3: ");

    for (const auto& num : incorrect) {
        Print(num);
    }
    
    return 0;
}