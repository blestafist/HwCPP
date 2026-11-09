#include <iostream>
#include <fstream>


// ============================= CONFIGURAIONS ==========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wynik.txt";

// ======================================================================


bool IsPalindrome (std::string& tempWord)
{
    for (int i = 0; i < tempWord.size() / 2; i++)
    {
        if (tempWord[i] != tempWord[tempWord.size() - i - 1]) { return false; }
    }
    return true;
}


int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    std::string tempWord;
    
    int counter = 0;

    while (inputFile >> tempWord)
    {
        if (IsPalindrome(tempWord)) { counter++; }
    } 

    std::cout << "ilość palindromów: " << counter;
    outputFile << "ilość palindromów: " << counter;
}