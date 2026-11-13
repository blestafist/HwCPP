#include <algorithm>
#include <array>
#include <iostream>
#include <string>


char DigitToChar(int digit) {
    switch(digit) {
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        case 16: return 'G';
        case 17: return 'H';
        default: return static_cast<char>(digit + '0');
    }
}


std::string DecToBase(int decimal, int base) {
    if (decimal == 0) { return "0"; }

    std::string output;
    while (decimal > 0) {
        char curr = DigitToChar(decimal % base);
        output += curr;

        decimal /= base;
    }
    std::reverse(output.begin(), output.end());

    return output;
}


int main() {
    constexpr std::array nums { 17, 89, 109, 994, 8706 };
    constexpr std::array bases { 5, 7, 11, 14 };

    char label = 'a';
    for (int base : bases) {
        std::cout << label << ": ";
        for (int num : nums) {
            std::cout << DecToBase(num, base) << ' ';
        }
        ++label;
        std::cout << '\n';
    }

    return 0;
}
