#include <iostream>
#include <fstream>


const std::string INPUT_FILE_NAME = "hasla2.txt";
const std::string OUTPUT_FILE_NAME = "wyniki05.txt";


bool IsPrime (int num)
{
    if (num < 2) { return false; }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) { return false; }
    }
    return true;
}

bool IsRule (std::string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (!IsPrime(word[i])) { return false; }
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
        if (IsRule(tempWord)) { std::cout << tempWord << "\n"; outputFile << tempWord << "\n"; }
    }

}