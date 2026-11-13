#include <iostream>
#include <fstream>


const std::string INPUT_FILE_NAME = "hasla2.txt";
const std::string OUTPUT_FILE_NAME = "wyniki04.txt";


bool IsSpesialCharIncluded (const std::string& word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == '$' || word[i] == '!' || word[i] == '%') { return true; }
    }
    return false;
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
        if (IsSpesialCharIncluded(tempWord) && tempWord.size() >= 12) { counter++; }
    }

    std::cout << counter;
    outputFile << counter;
}