#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>


// =============================== CONFIGURATION ===============================

const std::string INPUT_FILE = "galerie.txt";
const std::string OUTPUT_FILE_A = "wyniki4_2a.txt";
const std::string OUTPUT_FILE_B = "wyniki4_2b.txt";

using GalleryTuple = std::tuple<std::string, size_t, size_t>;

// =============================================================================


GalleryTuple ParseLine(const std::string& line);

void FindMinMaxArea(const std::vector<GalleryTuple>& data,
std::string& maxAreaCity, std::string& minAreaCity, size_t& maxArea, size_t& minArea);

void ProcessFile(std::vector<GalleryTuple>& data, std::string& maxAreaCity, std::string& minAreaCity, size_t& maxArea, size_t& minArea) {
    std::ifstream inputFile(INPUT_FILE);
    if (!inputFile) {
        std::cerr << "ERROR: File " << INPUT_FILE << " not found" << std::endl;
        std::exit(1);
    }  

    std::string line;
    while (std::getline(inputFile, line)) {
        auto result = ParseLine(line);
        data.push_back(result);
    }
    FindMinMaxArea(data, maxAreaCity, minAreaCity, maxArea, minArea);    
}


auto ParseLine(const std::string& line) 
-> GalleryTuple {
    std::istringstream iss(line);

    std::string country,    // Ignored
    city;

    size_t length = 0, width = 0;
    size_t galleryArea = 0;

    size_t unitsCounter = 0;

    iss >> country >> city;
    while (iss >> length >> width) {
        if (length == 0 && width == 0) break;   // Zeros indicate empty slots

        galleryArea += length * width;
        ++unitsCounter;
    }
    return std::make_tuple(city, galleryArea, unitsCounter);
}   


void PrintOutput(const std::vector<GalleryTuple>& data, 
const std::string& maxAreaCity, const std::string& minAreaCity, const size_t maxArea, const size_t minArea) {
    std::ofstream outputFileA(OUTPUT_FILE_A), outputFileB(OUTPUT_FILE_B);
    if (!outputFileA || !outputFileB) {
        std::cerr << "ERROR: Could not create outputFile" << std::endl;  
        std::exit(1);
    }
    
    auto PrintA = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFileA << ... << args) << '\n'; };
    std::cout << "a:\n";
    for (const auto& [city, area, units] : data) {
        PrintA(city, ' ', area, ' ', units);
    }

    auto PrintB = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFileB << ... << args) << '\n'; };
    std::cout << "b:\n";
    PrintB(maxAreaCity, ' ', maxArea, 
    "\n", minAreaCity, ' ', minArea);
}


void FindMinMaxArea(const std::vector<GalleryTuple>& data,
std::string& maxAreaCity, std::string& minAreaCity, size_t& maxArea, size_t& minArea) {
    for (auto& [city, area, units] : data) {
        if (area < minArea) { minArea = area; minAreaCity = city; }
        if (area > maxArea) { maxArea = area; maxAreaCity = city; }
    }
}


int main() {
    std::vector<GalleryTuple> data;
    data.reserve(50);

    std::string maxAreaCity,
    minAreaCity;

    size_t maxArea = 0,
    minArea = std::numeric_limits<size_t>::max();

    ProcessFile(data, maxAreaCity, minAreaCity, maxArea, minArea);

    PrintOutput(data, maxAreaCity, minAreaCity, maxArea, minArea);

    return 0;
}