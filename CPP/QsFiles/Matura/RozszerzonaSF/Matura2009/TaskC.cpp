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


int FindOverlapB_A (const std::string& A, const std::string& B) // return index B of the beginning of A in C number
{
    int lenB = B.size();
    
    for (int i = 1; i < lenB; i++) // goes throught B
    {
        bool flag = true;

        for (int j = 0; j < lenB - i; j++) // goes throught A from 0 to b prefix len
        {
            if (A[j] != B[j + i]) { flag = false; break; }
        }

        if (flag) { return i; }
    }

    return -1;
}


int FindOverlapA_B (const std::string& A, const std::string& B) // return index A of beginning of B in C number
{
    int lenA = A.size(),
    lenB = B.size();
    
    for (int i = lenA - lenB + 1; i < lenA; i++) // goes throught A
    {
        bool flag = true;

        for (int j = 0; j < lenA - i; j++) // goes throught B from 0 to len a prefix len
        {
            if (B[j] != A[i + j]) { flag = false; break; }
        }
        if (flag) { return i; }
    }
    
    return -1;
}


int main ()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    std::cout << "C\n";

    std::string wordA, wordB;

    int counter = 0;

    while (inputFile >> wordA >> wordB)
    {
        bool noRelation = (!Contains(wordA, wordB) &&
        FindOverlapB_A(wordA, wordB) == -1 && 
        FindOverlapA_B(wordA, wordB) == -1);

        if (noRelation) { counter ++;}
    }

    std::cout << counter;
    outputFile << counter;
}