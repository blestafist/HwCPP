#include <array>
#include <iostream>


// ======================== CONFIGURATION ========================

constexpr int DECIMAL_DIGITS = 10;

// ===============================================================


constexpr std::array<int, DECIMAL_DIGITS> PrecomputeFactorials() {
    std::array<int, DECIMAL_DIGITS> table {};
    table[0] = 1;
    for (int i = 1; i < DECIMAL_DIGITS; ++i) {
        table[i] = table[i - 1] * i;    // Reuse previous factorial: n! = (n - 1)! * n
    }
    return table;
}


constexpr std::array<int, DECIMAL_DIGITS> FACTORIALS_TABLE = PrecomputeFactorials();


bool IsFactorion(int num) {
    if (num <= 0) { return false; }

    int original = num;
    int factorialSum = 0;
    while (num > 0) {
        factorialSum += FACTORIALS_TABLE[num % 10];

        if (factorialSum > original) { return false; }
        num /= 10;
    }
    return factorialSum == original;
}


int main() {
    int count = 0;
    for (int i = 10; i <= 1000; ++i) {
        if (IsFactorion(i)) {
            std::cout << i << '\n';
            ++count;
        }
    }
    std::cout << "\nIlość liczb: " << count;
    return 0;
}