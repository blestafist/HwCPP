#include <iostream>
#include <fstream>

const std::string INPUT_FILE_NAME = "NAPIS.TXT";
const std::string OUTPUT_FILE_NAME = "wyniki05.txt";


bool IsAsciiCodeGrowing (const std::string& word)
{
    for (int i = 0; i < word.size() - 1; i ++)
    {
        if (word[i] > word [i + 1]) { return false; }
    }
    return true;
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
        if (IsAsciiCodeGrowing(tempWord)) { std::cout << tempWord << "\n"; outputFile << tempWord << "\n"; }
    }

}