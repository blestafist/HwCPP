#include <iostream>
#include <fstream>
using namespace std;

const string INPUT_FILE = "dane.txt";
const string OUTPUT_FILE = "zadanie4.txt";


bool IsPalindrome(string tempWord)
{
    for(int i = 0; i < tempWord.size() / 2; i++)
    {
            if(tempWord[i] != tempWord[tempWord.size()-1-i]) { return false; }
    }
    return true;
}

int main()
{

    ifstream inputFile(INPUT_FILE);
    ofstream outputFile(OUTPUT_FILE);

    string tempWord;

    while(inputFile >> tempWord)
        if(IsPalindrome(tempWord)) {cout << tempWord << endl; outputFile << tempWord << endl; }

    inputFile.close();
    outputFile.close();
    
    return 0;
}