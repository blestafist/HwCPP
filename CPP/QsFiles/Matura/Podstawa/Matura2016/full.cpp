#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>


// ======================== CONFIGURATION ========================

constexpr const char* INPUT_FILE = "dane_6.txt";
constexpr const char* OUTPUT_FILE = "wyniki_6.txt";

using Pair = std::pair<int, int>;

// ===============================================================


bool IsPrime(int num) {
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0 || num < 2) { return false; }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }
    return true;
}


// Checks if the absolute difference between two numbers is exactly 2
bool IsTwinNums(int n1, int n2) {
    return std::abs(n1 - n2) == 2;
}   


int main() {
    std::ifstream inputFile(INPUT_FILE);
    if (!inputFile) { std::cerr << "ERROR: File: " << INPUT_FILE << " not found" << std::endl; return 1; }

    std::ofstream outputFile(OUTPUT_FILE);
    if (!outputFile) { std::cerr << "ERROR: Could not create output file" << std::endl; return 1; }

    int primeCounter = 0;
    int maxPrime = 0,
    minPrime = std::numeric_limits<int>::max();

    int twinCounter = 0;
    std::vector<Pair> twins;

    int currentNum;
    int prevNum = -1;
    bool prevIsPrime = false;

    while (inputFile >> currentNum) {
        const bool currentIsPrime = IsPrime(currentNum);

        if (currentIsPrime) { 
            ++primeCounter; 

            maxPrime = std::max(currentNum, maxPrime);
            minPrime = std::min(currentNum, minPrime);
        }

        if (prevNum != -1) {
            if (currentIsPrime && prevIsPrime) {
                if (IsTwinNums(currentNum, prevNum)) {
                    ++twinCounter;
                    twins.push_back({ prevNum, currentNum });
                }
            }
        }

        prevNum = currentNum;
        prevIsPrime = currentIsPrime;
    }

    auto Print = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("6.1: ", primeCounter);
    Print("\n6.2: ", "Największa liczba pierwsza: ", maxPrime, " Najmniejsza liczba pierwsza: ", minPrime);
    Print("\n6.3: Liczba par: ", twinCounter);

    for (auto& p : twins) {
        auto [num1, num2] = p;
        Print(num1, " i ", num2);
    }

    return 0;
}