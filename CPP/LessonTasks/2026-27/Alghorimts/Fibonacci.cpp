#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

std::string OUTPUT_FILE = "output.md";

// =====================================================================

long fibonnaci (int n, long firstNum = 0, long secondNum = 1) { // 0(n)
    if (n == 0) { return firstNum; }
    else if (n == 1) { return secondNum; }

    return fibonnaci(n - 1, secondNum, firstNum + secondNum);
}

std::string to_bin (long num) { // O(n), jeśli nie brać pod uwagę przesuwanie string i reinicjalizowanie pamięci
    std::string result = "";
    while (num > 0) {
        result = (char)((num % 2) + '0') + result;
        num /= 2;
    }

    return result;
}

void AddLeadingZeroes (std::string& str) { // 0(n)
    int zeroesToAdd = 27 - str.length();
    for (int i = 0; i < zeroesToAdd; ++i) {
        str = "0" + str;
    }
}

bool IsPrime (long num) { // o(log n)
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0 || num < 2) { return false; }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }

    return true;
}

bool DoesHave6Ones (const std::string& str) { // O(n)
    int counter = 0;
    for (char c : str) {
        if (c == '1') { ++counter; }
    }

    return counter == 6;
}

int main () {
    std::ofstream outputFile (OUTPUT_FILE);
    std::string tempStr;


    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };
    for (int i = 1; i <= 40; ++i) {
        tempStr = to_bin(fibonnaci(i));
        AddLeadingZeroes(tempStr);
        Print(tempStr);
    }

    Print();
    Print("========================================");
    Print("Prime fibonnaci: ");

    for (int i = 1; i <= 40; ++i) {
        long fibonacciNum = fibonnaci(i);
        if (IsPrime(fibonacciNum)) {
            Print(i, ": ", fibonacciNum);
        }
    }

    Print();
    Print("========================================");
    Print("6-ones fibonnaci: ");

    for (int i = 1; i <= 40; ++i) {
        long fibonacciNum = fibonnaci(i);
        tempStr = to_bin(fibonacciNum);
        if (DoesHave6Ones(tempStr)) {
            Print(i, ": ", fibonacciNum, ": ", tempStr);
        }
    }

    return 0;
}
