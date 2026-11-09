#include <iostream>
#include <fstream>


const std::string INPUT_FILE_NAME = "hasla1.txt";
const std::string OUTPUT_FILE_NAME = "wyniki03.txt";

bool IsPalindrome (std::string word)
{
    for (int i = 0; i < word.size() - 1; i++)
    {
        if (word[i] != word[word.size() - 1 - i]) { return false; }
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

    while (inputFile >> tempWord)
    {
        if (IsPalindrome(tempWord)) { std::cout << tempWord << "\n"; outputFile << tempWord << "\n"; }
    }
}