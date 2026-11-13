#include <iostream>
#include <fstream>
using namespace std;

string const INPUT_FILE = "hasla.txt";

string const OUTPUT_FILE_A = "wynik4a.txt";
string const OUTPUT_FILE_B = "wynik4b.txt";
string const OUTPUT_FILE_C = "wynik4c.txt";

int IsEven(const string& tempPassword)
{
    return (tempPassword.size() % 2 == 0) ? true : false;
}

bool IsPalindrome(const string& tempPassword)
{
    for (int i = 0; i < tempPassword.size() / 2; i++)
    {
        if(tempPassword[i] != tempPassword[tempPassword.size() -1-i]) { return false; break; }
    }
    return true;
}

bool IsAsciiSum220(string tempPassword)
{
    for(int i = 0; i < tempPassword.size() - 2; i ++)
    {
        if(tempPassword[i] + tempPassword[i + 1] == 220) { return true; break; }
    }
    return false;
}
int main()
{
    ifstream inputFile (INPUT_FILE);    
    ofstream outputFileA (OUTPUT_FILE_A), outputFileB(OUTPUT_FILE_B), outputFileC(OUTPUT_FILE_C);

    string tempPassword;

    int counterOfEven = 0, counterOfNotEven = 0;

    while (inputFile >> tempPassword)
    {
        (IsEven(tempPassword)) ? counterOfEven++ : counterOfNotEven++;
    }
    cout << "Zadanie A" << endl;
    cout << "hasła parzyste: " << counterOfEven << endl << "hasła nie parzyste: " << counterOfNotEven <<endl;
    outputFileA << "hasła parzyste: " << counterOfEven << endl << "hasła nie parzyste: " << counterOfNotEven;

    inputFile.close();
    inputFile.open(INPUT_FILE);

    cout << "Zadanie B" << endl;
    while (inputFile >> tempPassword)
    {
        if(IsPalindrome(tempPassword)) { cout << tempPassword << endl; outputFileB << tempPassword << endl; }
    }
    
    inputFile.close();
    inputFile.open(INPUT_FILE);
    cout << "Zadanie C" << endl;
    while (inputFile >> tempPassword)
    {
        if(IsAsciiSum220(tempPassword)) { cout << tempPassword << endl; outputFileC << tempPassword << endl; }
    }

    inputFile.close();
    outputFileA.close(), outputFileB.close(), outputFileC.close();

}