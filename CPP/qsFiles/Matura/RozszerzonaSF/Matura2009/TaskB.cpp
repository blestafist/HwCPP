#include <iostream>
#include <fstream>


// =============================== CONFIGURATION ============================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "zad_5.txt";

// ==========================================================================


bool Contains (const std::string& text, const std::string& sub)
{
    for (int i = 0; i <= text.size() - sub.size(); i++)
    {
        int j = 0;
        while (j < sub.size() && text[i + j] == sub[j])
        {
            j++;
        }

        if (j == sub.size()) { return true; }
    }
    
    return false;
}


int main ()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    std::cout << "B\n";

    std::string WordA, WordB;

    int counter = 0;

    while (inputFile >> WordA >> WordB)
    {
        if (Contains(WordA, WordB)) { counter ++; }
    }

    std::cout << counter;
    outputFile << counter;
}