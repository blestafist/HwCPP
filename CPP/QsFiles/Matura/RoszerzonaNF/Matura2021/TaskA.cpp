#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


// =============================== CONFIGURATION ===============================

const std::string INPUT_FILE = "galerie.txt";
const std::string OUTPUT_FILE = "wyniki4_1.txt";

// =============================================================================


void ProcessFile(std::vector<std::pair<std::string, int>>& countries) {
    std::ifstream inputFile(INPUT_FILE);
    if (!inputFile) {
        std::cerr << "ERROR: File " << INPUT_FILE << " not found" << std::endl;
        std::exit(1);
    }

    std::string country;

    while (inputFile >> country) {
        std::string dummy;     // Ignore rest
        std::getline(inputFile, dummy);

        auto it = std::find_if(countries.begin(), countries.end(), [&](const auto& p) {
            return p.first == country; });

        if (it != countries.end()) {
            ++it->second;
        }   else {
            countries.push_back({country, 1});
        }
    }
}


void PrintOutput(const std::vector<std::pair<std::string, int>>& countries) {
    std::ofstream outputFile(OUTPUT_FILE);
    if (!outputFile) {
        std::cerr << "ERROR: Could not create outputFile" << std::endl;  
        std::exit(1);
    }
    
    auto Print = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    for (const auto& p : countries) {
        auto [country, cityCount] = p;
        Print(country, ' ', cityCount);
    }
}


int main() {
    std::vector<std::pair<std::string, int>> countries;

    ProcessFile(countries);
    PrintOutput(countries);

    return 0;
}