#include <iostream>
#include <fstream>
#include <vector>


// ================================== CONFIGURATIONS ====================================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string OUTPUT_FILE_NAME = "wynik4.txt";

// ======================================================================================

bool IsZerosMore (const std::string& tempString)
{
    int counter = 0;
    for (char c : tempString)
    {
        if (c == '0') { counter++; }
        else { counter--; }
    }
    return counter > 0;
}


bool ContainsBlocks (const std::string& tempString)
{
    int changesCount = 0;

    if (tempString.empty() || tempString[0] != '0') { return false; }

    for (size_t i = 0; i + 1 < tempString.size(); i++)
    {
        if (tempString[i] != tempString[i + 1]) { changesCount++; }
    }
    return changesCount == 1;
}


int BiggestBlocksOf0 (const std::string& tempString)
{
    int biggestBlock = 0,
    counter = 0;

    for (char c : tempString)
    {
        
        if (c == '0') { counter++; biggestBlock = std::max(biggestBlock, counter); }
        else
        {
            counter = 0;
        }
    
    }
    return biggestBlock;
}


int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile"; return -1; }

    std::string tempString;

    std::vector<std::string> StrWithMax0Blocks;

    int counterMoreZeros = 0,
    counterContainsBlocks = 0,
    maxCount0Blocks = 0;

    while (inputFile >> tempString)
    {
        if (IsZerosMore(tempString)) { counterMoreZeros++; }
        if (ContainsBlocks(tempString)) { counterContainsBlocks++; }
        
        int result = BiggestBlocksOf0(tempString);
        if (result > maxCount0Blocks) { maxCount0Blocks = result; StrWithMax0Blocks.clear(); StrWithMax0Blocks.push_back(tempString); }
        else if (result == maxCount0Blocks) { StrWithMax0Blocks.push_back(tempString); }
        
    }

    auto Print = [&] (auto&& ... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    Print("ZadanieA ", counterMoreZeros);
    Print("ZadanieB ", counterContainsBlocks);
    Print("ZadanieC ", maxCount0Blocks);
    
    std::cout << "słowa zawierające najdłuższy block: " << "\n";

    for (const std::string& str : StrWithMax0Blocks)
    {
        Print(str);
    }
}