#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>


// ========================= CONFIGUTAION =========================

const std::string INPUT_FILE = "liczby.txt";
const std::string OUTPUT_FILE = "wyniki5.txt";

// ================================================================


bool IsPalindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return original == reversed;
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

    int maxEvenNum = -1;
    long long allDigitsSum = 0;

    std::vector<int> palindromes;
    std::vector<int> digitSumOver30;

    int number;
    while (inputFile >> number) {
        if (number % 2 == 0) { 
            maxEvenNum = std::max(number, maxEvenNum);
        }

        if (IsPalindrome(number)) { palindromes.push_back(number); }

        int digitsSum = SumOfDigits(number);
        if (digitsSum > 30) { digitSumOver30.push_back(number); }

        allDigitsSum += digitsSum;
    }

    auto Print = [&](auto... args) { (std::cout << ... << args) << '\n'; (outputFile << ... << args) << '\n'; };

    Print("5.1: ", maxEvenNum);
    Print("\n5.2: ");

    for (auto i : palindromes) {
        Print(i);
    }

    Print("\n5.3:\nLiczby, których suma cyfr większa od 30");

    for (auto i : digitSumOver30) {
        Print(i);
    }

    Print("\nSuma wszystkich cyfr w pliku: ", allDigitsSum);

    return 0;
}