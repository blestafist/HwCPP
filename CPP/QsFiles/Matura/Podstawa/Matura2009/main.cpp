#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

bool IsRootPrime(int tempNum)
{
    if (sqrt(tempNum) != int(sqrt(tempNum))) { return false; } 
        
    tempNum = sqrt(tempNum);

    if (tempNum < 2) {return false ;}

    for(int i = 2; i * i <= tempNum; i++)
    {
        if (tempNum % i == 0) { return false; }
    }
    return true;
}

int main()
{
    const string INPUT_FILE = "liczby.txt";
    const string OUTPUT_FILE = "zad_5.txt";
    
    ifstream inputFile(INPUT_FILE);
    ofstream outputFile(OUTPUT_FILE);

    int tempNum;

    if(!inputFile.is_open()) cout << "FileError";
    
    while(inputFile >> tempNum)
    {    
        if(IsRootPrime(tempNum)) { cout << tempNum <<endl;  outputFile  << tempNum << endl; }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}