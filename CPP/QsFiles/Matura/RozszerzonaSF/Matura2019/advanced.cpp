#include <iostream>
#include <fstream>
#include <utility>  // std::pair
#include <optional>
#include <vector>


// ========================= CONFIGURATION ==========================

const std::string INPUT_FILE_NAME = "dzialki.txt";
const std::string OUTPUT_FILE_NAME = "wynik4.txt";

const int NUM_PLOTS = 50;
const int DIMENSIONS = 30;

// ==================================================================


void ParseFile(char (&arr)[NUM_PLOTS][DIMENSIONS][DIMENSIONS]) {
    std::ifstream inputFile(INPUT_FILE_NAME);

    if (!inputFile) { 
        std::cerr << "ERROR: File " << INPUT_FILE_NAME << " not found" << std::endl;
        std::exit(1);
    }

    char temp;
    for (int i = 0; i < NUM_PLOTS; i++) {
        for (int y = 0; y < DIMENSIONS; y++) {
            for (int x = 0; x < DIMENSIONS; x++) {
                inputFile >> temp;
                arr[i][y][x] = temp;
            }
        }
    }
}


// A helper func, not used in real program
void Print3D_Array (const char (&arr)[NUM_PLOTS][DIMENSIONS][DIMENSIONS]) {
    for (int i = 0; i < NUM_PLOTS; i++) {
        for (int y = 0; y < DIMENSIONS; y++) {
            for (int x = 0; x < DIMENSIONS; x++) {
                std::cout << arr[i][y][x] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}


// Checks if grass ('*') covers at least 70 % of the plot area
bool AtLeast70PercentGrass (const char (&arr)[NUM_PLOTS][DIMENSIONS][DIMENSIONS], int plotNum) {
    int grassCounter = 0;

    for (int y = 0; y < DIMENSIONS; y++) {
        for (int x = 0; x < DIMENSIONS; x++) {    
            if (arr[plotNum][y][x] == '*') { 
                grassCounter++;
                if (grassCounter >= 630) { return true; }   // 630 is the threshold (70% of 900 pixels)
            }
        }
    }     
    return false;
}


// Returs plots with at least 70% grass
int Count70PercentGrassPlots (const char (&arr)[NUM_PLOTS][DIMENSIONS][DIMENSIONS]) {
    int counter = 0;

    for (int i = 0; i < NUM_PLOTS; i++) {
        if (AtLeast70PercentGrass(arr, i)) { counter++; }
    }

    return counter;
}


bool AreIdenticalRotated (const char (&arr)[NUM_PLOTS][DIMENSIONS][DIMENSIONS], int firstPlot, int secondPlot) {
    for (int y = 0; y < DIMENSIONS; y++) {
        for (int x = 0; x < DIMENSIONS; x++) {
            if (arr[firstPlot][y][x] != arr[secondPlot][DIMENSIONS - y - 1][DIMENSIONS - x - 1]) { return false; }
        }
    }
    
    return true;
}


std::optional<std::pair<int, int>> FindSymmetryPlotNums (const char (&arr)[NUM_PLOTS][DIMENSIONS][DIMENSIONS]) {
    for (int i = 0; i < NUM_PLOTS; i++) {
        for (int j = i + 1; j < NUM_PLOTS; j++) {
            if (AreIdenticalRotated(arr, i, j)) { return std::make_pair(i + 1, j + 1); }
        }
    }

    return std::nullopt;
}


// Searches for the largest area from the upper right corner without obstacles
int BiggestCleanSquare (const char (&arr)[NUM_PLOTS][DIMENSIONS][DIMENSIONS], int plotNum) {
    for (int i = 0; i < DIMENSIONS; i++) {     // Increases size of the area with each iteration (i : i)
        if (arr[plotNum][i][i] == 'X') { return i; }    // Return i mean return one less from wrong (index)

        int x = i, y = i;
        for (int j = 1; j <= i; j++) {   // Cheks y offsets
            int ny = y - j;
            if (arr[plotNum][ny][x] == 'X') { return i; }
        }  
        for (int j = 1; j <= i; j++) {   // Cheks x offsets
            int nx = x - j;
            if (arr[plotNum][y][nx] == 'X') { return i; }
        }      
    }
    return DIMENSIONS;  // If the loop reaches the end - area is equal plot size
}


std::vector<int> FindCleanestPlotNums (const char (&arr)[NUM_PLOTS][DIMENSIONS][DIMENSIONS]) {  // Returns a list of numbers the cleanest plots
    int maxSize = 0, currSize = 0;
    std::vector<int> nums;

    for (int i = 0; i < NUM_PLOTS; i++) {
        currSize = BiggestCleanSquare(arr, i);

        if (maxSize < currSize) { maxSize = currSize; nums.clear(); nums.push_back(i + 1); }
        else if (maxSize == currSize) { nums.push_back(i + 1); }
    }
    return nums;
}


int main () {
    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    char mainArr[NUM_PLOTS][DIMENSIONS][DIMENSIONS];

    ParseFile(mainArr);

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("4.1: ", Count70PercentGrassPlots(mainArr));

    auto result = FindSymmetryPlotNums(mainArr);

    if (result) {
        auto [a, b] = *result;
        Print("4.2: ", a, " i ", b);
    }
    else {
        Print ("4.3 ", "BRAK");
    }

    std::vector<int> nums = FindCleanestPlotNums(mainArr);

    Print ("4.3");
    Print ("nr działki(kilku):");

    for (int i : nums) {
        Print(i);
    }
    
    Print ("długość boku placu: ", BiggestCleanSquare(mainArr, nums[0] - 1));

    return 0;
}