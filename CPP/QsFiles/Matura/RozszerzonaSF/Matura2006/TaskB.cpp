#include <iostream>
#include <fstream>


// ============================= CONFIGURAIONS ==========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wynik.txt";

const char EVEN_CHARS[] { 'A', 'C', 'E' };

// ======================================================================


int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    std::string tempWord;
    
    int evenCounter = 0;

    while (inputFile >> tempWord)
    {
       for (char c : EVEN_CHARS)
       {
            if (tempWord.back() == c) { evenCounter++; break; }
       }
    }

    std:: cout << "liczb parzystych: " << evenCounter;
    outputFile << "liczb parzystych: " << evenCounter;

}