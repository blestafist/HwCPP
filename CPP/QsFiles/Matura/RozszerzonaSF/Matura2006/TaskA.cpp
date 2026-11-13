#include <iostream>
#include <fstream>
#include <unordered_map>


// ============================= CONFIGURAIONS ==========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wynik.txt";

// ======================================================================


int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    std::string tempWord;
    
    std::unordered_map<std::string, int> wordsCounter;

    while (inputFile >> tempWord)
    {
        wordsCounter[tempWord]++;
    }

    int moreThan1OccCount = 0,
    maxOccCount = 0;

    std::string maxOccWord; 

    for (const auto& [word, count] : wordsCounter)
    {
        if (count > 1) 
        { 
            moreThan1OccCount++; 
            if (count > maxOccCount) { maxOccCount = count; maxOccWord = word; }
        }
    }

    auto Print = [&] (auto&& ... argc) { (std::cout << ... << argc) << "\n"; (outputFile << ... << argc ) << "\n"; };

    Print("Słow występujących więcej niż raz: ", moreThan1OccCount);
    Print("Słowo o największej liczbie wystąpień: ", maxOccWord);
    Print("Liczba jego wystąpień: ", maxOccCount);

}