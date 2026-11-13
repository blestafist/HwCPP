#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
#include <unordered_set>


// =============================== CONFIGURATION ===============================

const std::string INPUT_FILE = "galerie.txt";
const std::string OUTPUT_FILE = "wyniki4_3.txt";

// =============================================================================


std::pair<size_t, std::string> CountUniqueAreas(const std::string& line);


void ProcessFile(std::string& mostDifferencesCity, std::string& fewestDifferencesCity,
size_t& mostDifferences, size_t& fewestDifferences) {
    std::ifstream inputFile(INPUT_FILE);
    if (!inputFile) {
        std::cerr << "ERROR: File " << INPUT_FILE << " not found" << std::endl;
        std::exit(1);
    }  

    std::string line;

    while (std::getline(inputFile, line)) {
        auto [uniqueTypeCount, currCity] = CountUniqueAreas(line);

        if (uniqueTypeCount > mostDifferences) { mostDifferences = uniqueTypeCount; mostDifferencesCity = currCity; }
        if (uniqueTypeCount < fewestDifferences) { fewestDifferences = uniqueTypeCount; fewestDifferencesCity = currCity; }
    }
}


std::pair<size_t, std::string> CountUniqueAreas(const std::string& line) {
    std::istringstream iss(line);

    std::string country,    // Ignored
    city;

    size_t length = 0, width = 0;

    std::unordered_set<size_t> uniqueAreas;

    iss >> country >> city;
    while (iss >> length >> width) {   // len or width == 0 - unit no exits
        if (length == 0 && width == 0) break;

        size_t unitArea = length * width;
        uniqueAreas.insert(unitArea);
    }

    std::pair<size_t, std::string> differences;
    differences.first = uniqueAreas.size();
    differences.second = city;
    
    return differences;
}

    
void PrintOutput(const std::string& mostDifferencesCity, const std::string& fewestDifferencesCity,
const size_t mostDifferences, const size_t fewestDifferences) {
    std::ofstream outputFile(OUTPUT_FILE);
    if (!outputFile) {
        std::cerr << "ERROR: Could not create outputFile" << std::endl;  
        std::exit(1);
    }

    auto Print = [&](auto... args) { (std::cout << ... << args); (outputFile << ... << args); };

    Print(mostDifferencesCity, " ", mostDifferences, '\n', fewestDifferencesCity, " ", fewestDifferences);
}


int main() {
    std::string mostDifferencesCity = "",
    fewestDifferencesCity = "";

    size_t mostDifferences = 0,
    fewestDifferences = std::numeric_limits<size_t>::max();

    ProcessFile(mostDifferencesCity, fewestDifferencesCity, mostDifferences, fewestDifferences);
    PrintOutput(mostDifferencesCity, fewestDifferencesCity, mostDifferences, fewestDifferences);

    return 0;
}