#include <iostream>
#include <fstream>

const std::string INPUT_FILE = "";
const std::string OUTPUT_FILE = "";

int main()
{
    std::ifstream inputFile(INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return 1; }

    std::ofstream outputFile(OUTPUT_FILE);
    std::string tempStr;

    while (inputFile >> tempStr) {

    }

    return 0;
}