#include <iostream>
#include <fstream>

const std::string INPUT_FILE_NAME = "hasla.txt";
const std::string OUTPUT_FILE_NAME = "wyniki04.txt";


bool IsAsciiSum220 (std::string word)
{
    for (int i = 0; i < word.size() - 1; i++)
    {
        if (word[i] + word[i+1] == 220) { return true;}
    }
    return false;
}


int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile"; return -1; }

    std::string tempWord;

    while (inputFile >> tempWord)
    {
        if (IsAsciiSum220(tempWord)) { std::cout << tempWord << "\n"; outputFile << tempWord << "\n"; }
    }
}