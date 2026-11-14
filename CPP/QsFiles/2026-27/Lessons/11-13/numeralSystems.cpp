#include <algorithm>
#include <array>
#include <iostream>
#include <string>


std::string DecToBase(int decimal, int base) {
    if (decimal == 0) { return "0"; }
    static constexpr char digits[] = "0123456789ABCDEFGH";

    std::string output;
    while (decimal > 0) {
        char curr = digits[decimal % base];
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
