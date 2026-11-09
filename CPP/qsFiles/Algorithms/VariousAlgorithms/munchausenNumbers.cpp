#include <array>
#include <iostream>


// ======================== CONFIGURATION ========================

constexpr int DECIMAL_DIGITS = 10;

// ===============================================================


constexpr unsigned long long Power (int base, int exp) {
    if (exp == 0) { return 1; }
    if (base == 0) { return 0; }

    unsigned long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}


constexpr std::array<unsigned long long, DECIMAL_DIGITS> PrecomputePowers() {
    std::array<unsigned long long, DECIMAL_DIGITS> table {};

    for (int i = 0; i < DECIMAL_DIGITS; ++i) {
        table[i] = Power(i, i);
    }
    table[0] = 0;   // comment / uncomment this line to follow / not follow the OEIS rules
    return table;
} 


constexpr std::array<unsigned long long, DECIMAL_DIGITS> POWERS_TABLE = PrecomputePowers();


bool IsMunchausen(int num) {
    if (num < 0) return false;

    int original = num;
    unsigned long long sum = 0;
    
    while (num > 0) {
        sum += POWERS_TABLE[num % 10];

        if (sum > static_cast<unsigned long long>(original)) { return false; }

        num /= 10;
    }
    return sum == static_cast<unsigned long long>(original);
}


int main() {
    int counter = 0;
    for (int i = 10; i <= 1000; ++i) {
        if (IsMunchausen(i)) {
            std::cout << i << ' ';
            ++counter;
        }
    }
    std::cout <<"\nIlość tych liczb: " << counter;
    return 0;
}