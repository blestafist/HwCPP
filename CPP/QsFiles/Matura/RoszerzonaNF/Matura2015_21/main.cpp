#include <array>
#include <cstdlib>  // std::exit
#include <fstream>
#include <iostream>
#include <string_view>


// ============================ CONFIGURATION ============================

const std::array<std::string, 3> INPUT_FILES { "liczby1.txt", "liczby2.txt", "liczby3.txt" };
const std::string OUTPUT_FILE = "podzielność.txt";

// =======================================================================


[[nodiscard]] bool IsDivisible (std::string_view binary, const int divisor) {
    int remainder = 0;

    for (char c : binary) {
        int bit = c - '0';
        remainder = ((remainder << 1) + bit) % divisor;
    }
    return remainder == 0;
}


void ProcessFile (const std::string& fileName, int& c2, int& c3, int& c5) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "ERROR: File " << fileName << " not found" << std::endl;
        std::exit(1);
    }

    std::string binaryStr;

    while (inputFile >> binaryStr) {
        if (binaryStr.empty()) continue;

        if (binaryStr.back() == '0') { ++c2; }
        if (IsDivisible(binaryStr, 3)) { ++c3; }
        if (IsDivisible(binaryStr, 5)) { ++c5; }
        
    }
}


int main() { 
    std::ofstream outputFile(OUTPUT_FILE);
    if (!outputFile) { std::cerr << "ERROR: Could not create outputFile" << std::endl; return 1; }

    for (const auto& fileName : INPUT_FILES) {
        int count2 = 0, count3 = 0, count5 = 0;
        ProcessFile(fileName, count2, count3, count5);

        std::cout << "dla pliku " << fileName << ":\nliczb podzilnych przez 2: " << count2
        << "\nliczb podzilnych przez 3: " << count3 << "\nliczb podzilnych przez 5: " << count5 << "\n\n";

        outputFile << count2 << '\n' << count3 << '\n' << count5 << '\n';
    }

    return 0;
}