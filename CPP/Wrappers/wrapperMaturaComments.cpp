/*  
    !!!
    ONLY EXAMPLE, USE Wrapper-Matura.cpp / MWP.cpp (Minimal-Wrapper-Matura.cpp) in your project
    !!!
*/


#include <iostream>                                 // I / O
#include <fstream>                                  // File I / O
#include <string>                                   // Required by std::string


// ====================================== configuraiton ======================================

const std::string INPUT_FILE = "input.txt";         // place here your input file name
const std::string OUTPUT_FILE = "output.txt";       // place here your output file name

// ===========================================================================================


// place for custom functions ↓
void CustomFunction (const std::string& str) {      // only an example
    // some logic ...
}


// main (program entry point) ↓
int main () {
    std::ifstream inputFile (INPUT_FILE);           // declare ifstream (input-file stream) & check whether the file is opened
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; } 

    std::ofstream outputFile (OUTPUT_FILE);         // declare ofstream (output-file stream) -||-
    if (!outputFile) { std::cerr << "Error while opening output file!"; return 1; }

    auto Print = [&] (auto&&... argc) {             // Easy-print lambda (writes in stdout & outputFile), uses C++ 17 folding expression
        (std::cout << ... << argc) << "\n";
        (outputFile << ... << argc) << "\n";
    };
    
    std::string tempStr;                            // a string which is used to read the stream


    while (inputFile >> tempStr) {                  // read input file, delim by ' ' or '\n'
        // do some logic, for example
        CustomFunction(tempStr);
    }

    // Print results
    Print("HelloWorld(print)", tempStr);

    // no need to close the input file, the auto-destructor will do that automatically
    
    return 0;
}
