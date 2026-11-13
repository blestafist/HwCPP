#include <iostream>
#include <fstream>


bool IsPrime (int tempInt)
{
    if (tempInt < 2) { return false; }

    for (int i = 2; i * i <= tempInt; i++)
    {
        if (tempInt % i == 0) { return false; }
    }
    return true;
}


int SumOfDigits (int tempInt)
{
    int sum = 0;
    while (tempInt > 0) { sum += tempInt % 10; tempInt /= 10; }
    return sum;
}


bool IsBinarySumPrime (int tempInt)
{
    int sum = 0;
    
    while (tempInt > 0)
    {
        sum += tempInt % 2;
        tempInt /= 2;
    }
    return IsPrime(sum);
}


bool IsSuperBPrime(int n)
{
    return (IsPrime(SumOfDigits(n)) && IsBinarySumPrime(n) && IsPrime(n));
}


void WriteToFile (const std::string& fileName, int downRange, int upperRange)
{
    std::ofstream outputFile(fileName);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return; }

    int counter = 0;

    for (int i = downRange; i <= upperRange; i ++)
    {
        if (IsSuperBPrime(i)) 
        {  
            counter++;
            outputFile << i << "\n";
        }
    }

    std::cout << "ilość liczb dla przedziału <" << downRange << ":" << upperRange << ">\n" << counter << "\n";
}


int main()
{
    WriteToFile("1.txt", 2, 1000);
    WriteToFile("2.txt", 100, 10000);
    WriteToFile("3.txt", 1000, 100000);
}