#include <iostream>
#include <fstream>


// ==================================== CONFIGURAION ===============================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string OUTPUT_FILE_NAME1 = "hasla_b.txt";
const std::string OUTPUT_FILE_NAME2 = "slowa_b.txt";

// =================================================================================


bool IsPalindrome (const std::string& origin, int len)
{
    for (int i = 0; i < len / 2; i ++)
    {
        if (origin[i] != origin[len - i - 1]) { return false; }
    }
    return true;
}


std::string ComposeReversedW2 (const std::string& origin)
{
    int w1Len = 1;

    for (int i = origin.size(); i >= 1; i--)
    {
        if (IsPalindrome(origin, i)) { w1Len = i; break; }
    }
    
    std::string result = "";

    for (int i = origin.size() - 1; i > w1Len - 1; i--)
    {
        result += origin[i];
    }

    return result;
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
    shortestSize = 31,
    lenSumsPasswords = 0;

    std::string len12passwords;

    while (inputFile >> tempWord)
    {
        std::string password = ComposeReversedW2(tempWord) += tempWord;

        std::cout << password << "\n";
        outputFile1 << password << "\n";
        
        int passwordSize = password.size();

        if (passwordSize == 12) { len12passwords += password + "\n"; }

        if (longestSize < passwordSize) { longestSize = passwordSize; longest = password; }
        else if (shortestSize > passwordSize) { shortestSize = passwordSize; shortest = password; }

        lenSumsPasswords += passwordSize;
    }
    
    auto Print = [&] (auto&& ... argc) { (std::cout << ... << argc) << "\n"; (outputFile2 << ... << argc) << "\n"; };

    Print("1.\n", "hasła o długości 12: \n", len12passwords);
    Print("2.\n", "najdłuższe hasło: ", longest, " najkrótsze hasło: ", shortest);
    Print("3.\n", "suma dlugości haseł: ", lenSumsPasswords); 

}
