#include <iostream>
#include <fstream>


// =============================== CONFIGURATION ============================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "zad_5.txt";

// ==========================================================================


bool IsPalindrome (const std::string& tempString)
{
    for (int i = 0; i < tempString.size() / 2; i++)
    {
        if (tempString[i] != tempString[tempString.size() - i - 1]) { return false; }
    }
    return true;
}


int main ()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    std::cout << "A\n";
    outputFile << "A\n";

    std::string tempWord;
    int counter = 0;
    
    while (inputFile >> tempWord)
    {
        if (IsPalindrome(tempWord)) { counter ++; }
    }
    
    std::cout << counter;
    outputFile << counter;
}