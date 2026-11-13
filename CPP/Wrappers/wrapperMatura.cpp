#include <iostream>
#include <fstream>
#include <string>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE = "input.txt"; 
const std::string OUTPUT_FILE = "output.txt"; 

// =================================================================================


int main() {
	std::ifstream inputFile (INPUT_FILE);
	if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

	std::ofstream outputFile (OUTPUT_FILE);
	if (!outputFile) { std::cerr << "Error while opening output file!"; return 1; }

	auto Print = [&] (auto&&... argc) {
        (std::cout << ... << argc) << "\n";
        (outputFile << ... << argc) << "\n";
    };

	std::string tempStr;
	// int tempInt

	while (inputFile >> tempStr) {
	    
	}

	return 0;
}
