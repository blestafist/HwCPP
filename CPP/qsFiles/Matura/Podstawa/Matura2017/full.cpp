#include <array>
#include <fstream>
#include <iostream>
#include <numeric>


// ======================== CONFIGUTAION ========================

constexpr const char* INPUT_FILE = "liczby.txt";
constexpr const char* OUTPUT_FILE = "wyniki4.txt";

// ==============================================================


// Calculates GCD of three numbers
int GCD(int n1, int n2, int n3) {
    return std::gcd(std::gcd(n1, n2), n3);
}


int SumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10; 
    }
    return sum;
}


int main() {
    std::ifstream inputFile(INPUT_FILE);
    if (!inputFile) { std::cerr << "ERROR: File " << INPUT_FILE << " not found" << std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE);
    if (!outputFile) { std::cerr << "ERROR: Could not create output file" << std::endl; return 1; }

    int growingCounter = 0;
    unsigned long long gcdTotalSum = 0;

    int digitsSumEqual35 = 0;
    int maxDigitSum = 0,
    maxDigitSumCount = 0;

    std::array<int, 3> numbers {};
    
    while (inputFile >> numbers[0] >> numbers[1] >> numbers[2]) {
        if (numbers[0] < numbers[1] && numbers[1] < numbers[2]) { ++growingCounter; }

        const int currentGcd = GCD(numbers[0], numbers[1], numbers[2]);
        gcdTotalSum += currentGcd;

        int digitsSumInLine = 0;
        for (int n : numbers) {
            digitsSumInLine += SumOfDigits(n);
        }
        
        if (digitsSumInLine == 35) { ++digitsSumEqual35; }

        if (digitsSumInLine > maxDigitSum) {
            maxDigitSum = digitsSumInLine;
            maxDigitSumCount = 1;
        }
        else if (digitsSumInLine == maxDigitSum) { ++maxDigitSumCount; }
    }

    auto Print = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("4.1: ", growingCounter);
    Print("\n4.2: ", gcdTotalSum);
    Print("\n4.3: liczba wierszy z sumą cyfr 35: ", digitsSumEqual35, "\nnajwiększa suma cyfr w wierszu: ", maxDigitSum,
          "\nliczba jej wystąpień: ", maxDigitSumCount);

    return 0;
}