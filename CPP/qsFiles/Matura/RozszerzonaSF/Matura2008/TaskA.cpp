#include <iostream>
#include <fstream>


// ==================================== CONFIGURAION ===============================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string OUTPUT_FILE_NAME1 = "hasla_a.txt";
const std::string OUTPUT_FILE_NAME2 = "slowa_a.txt";

// =================================================================================


void ReverseWord (std::string& word)
{
    int n = word.size();

    for (int i = 0; i < n / 2; i++)
    {
        char temp = word[i];
        word[i] = word[n - i - 1];
        word[n - i - 1] = temp; 
    }
}


int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile1(OUTPUT_FILE_NAME1),
    outputFile2(OUTPUT_FILE_NAME2);

    if (!outputFile1 || !outputFile2) { std::cerr << "Error while opening outputFile\n"; return -1; }

    std::string tempWord,
    longest, 
    shortest;

    int longestSize = 0,
    shortestSize = 31;

    while (inputFile >> tempWord)
    {
        ReverseWord(tempWord);
        std::cout << tempWord << "\n";
        outputFile1 << tempWord << "\n";

        int tempWordSize = tempWord.size();

        if (longestSize < tempWordSize) { longestSize = tempWordSize; longest = tempWord; }
        else if (shortestSize > tempWordSize) { shortestSize = tempWordSize; shortest = tempWord; }
    }
    
    auto Print = [&] (auto&& ... argc) { (std::cout << ... << argc) << "\n"; (outputFile2 << ... << argc) << "\n"; };

    Print("najdłuższe hasło: ", longest, " jego długość: " ,longestSize);
    Print("najkrótsze hasło: ", shortest, " jego długość: " ,shortestSize);

}
