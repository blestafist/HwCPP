#include <iostream>
#include <fstream>

// ============================== CONFIGURATIONS ===================================

const std::string INPUT_FILE_NAME = "PARY_LICZB.TXT";
const std::string OUTPUT_FILE_NAME = "ZADANIE5.TXT";

// ==================================================================================


short GCD(short a, short b)
{
    if (b == 0)
        return a;

    return GCD(b, a%b);
}


bool IsSumOfDigitsSame(short num1, short num2)
{
    short sum1 = 0, sum2 = 0;

    while (num1 > 0)
    {
        sum1 += num1 % 10;
        num1 /= 10;
    }

    while (num2 > 0)
    {
        sum2 += num2 % 10;
        num2 /= 10;
    }
    return sum1 == sum2;
}


int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while openig outputFile\n"; return -1; }

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    short tempNum1, tempNum2, 
    counterDivisible = 0, 
    counterNOD1 = 0, 
    counterSameSum = 0;

    while (inputFile >> tempNum1 >> tempNum2)
    {
        if (tempNum1 % tempNum2 == 0 || tempNum2 % tempNum1 == 0) { counterDivisible ++; }

        if (GCD(tempNum1, tempNum2) == 1) { counterNOD1++; }

        if (IsSumOfDigitsSame(tempNum1, tempNum2)) { counterSameSum++; }
    }

    Print("ZadanieA: ", counterDivisible);
    Print("ZadanieB: ", counterNOD1);
    Print("ZadanieC: ", counterSameSum);
}
