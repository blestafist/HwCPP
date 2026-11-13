#include <iostream>
#include <fstream>


// =============================== CONFIGURATION ============================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "slowa.txt";

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


int FindOverlapB_A (const std::string& A, const std::string& B)  // Searches for an overlap of B's suffix with A's prefix (result: B + A).

{
    int lenB = B.size();
    
    for (int i = 1; i < lenB; i++)  // Goes throught B.
    {
        bool flag = true;

        for (int j = 0; j < lenB - i; j++)  // Goes throught A from 0 to b prefix len.
        {
            if (A[j] != B[j + i]) { flag = false; break; }
        }

        if (flag) { return i; }  // Returns the index in B where the match with the beginning of A starts.
    }

    return -1;
}   


int FindOverlapA_B (const std::string& A, const std::string& B)  // Searches for an overlap of A's suffix with B's prefix (result: A + B).
{
    int lenA = A.size(),
    lenB = B.size();
    
    for (int i = lenA - lenB + 1; i < lenA; i++)  // Goes throught A.
    {
        bool flag = true;

        for (int j = 0; j < lenA - i; j++)  // Goes throught B from 0 to len a prefix len.
        {
            if (B[j] != A[i + j]) { flag = false; break; }
        }
        if (flag) { return i; }     // Returns the index in A where the match with the beginning of B starts.
    }

    return -1;
}


std::string ComposeShortestWordC (const std::string& A, const std::string& B)
{
    std::string word1 = "", word2 = "";

    int sufAprefB = FindOverlapB_A(A, B);
    int prefAsufB = FindOverlapA_B(A, B);

    if (Contains(A, B)) { return A ;}

    if (sufAprefB != -1) 
    {  
        word1 = B.substr(0, sufAprefB) + A;
    }
    
    if (prefAsufB != -1)
    {
        word2 = A.substr(0, prefAsufB) + B;
    }
    
    if (!word1.empty() && !word2.empty()) { return word1.size() <= word2.size() ? word1 : word2; }
    else if (!word1.empty()) { return word1; }
    else if (!word2.empty()) { return word2; }
    else { return A + B; }
}


int main ()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    std::cout << "D\n";

    std::string wordA, wordB;

    while (inputFile >> wordA >> wordB)
    {
        std::string wordC = ComposeShortestWordC(wordA, wordB);
        
        std::cout << wordC << "\n";
        outputFile << wordC << "\n";
    }
}